#include "libtww/include/JSystem/JUtility/JUTGamePad.h"
#include "gz_flags.h"
#include "cheats.h"
#include "commands.h"
#include "controller.h"
#include "libtww/include/SSystem/SComponent/c_counter.h"
#include "menu.h"
#include "rels/include/defines.h"
#include "menus/utils/menu_mgr.h"
#include "libtww/include/m_Do/m_Do_printf.h"

#define BUTTON_STATES 12
#define REPEAT_TIME 4
#define REPEAT_DELAY 5
#define WINDOW_LENGTH 30

#define buttonStatus (mPadStatus.button)
#define A_BUTTON (CButton::A)
#define TRIGGER_BUTTONS (CButton::L | CButton::R)

static uint16_t sButtonsLastFrame = 0;
static uint16_t sButtons = 0;
static uint16_t sButtonsPressed = 0;
static uint16_t sCursorEnableDelay = 0;

u8 a_presses_per_window = 0;
u8 b_presses_per_window = 0;
u8 a_presses[WINDOW_LENGTH] = {0};
u8 b_presses[WINDOW_LENGTH] = {0};

struct ButtonState {
    uint16_t button;
    uint32_t pressed_frame;
    bool is_down;
};

static ButtonState buttonStates[BUTTON_STATES] = {
    {CButton::DPAD_LEFT, 0xFFFFFFFF, false}, {CButton::DPAD_RIGHT, 0xFFFFFFFF, false},
    {CButton::DPAD_DOWN, 0xFFFFFFFF, false}, {CButton::DPAD_UP, 0xFFFFFFFF, false},
    {CButton::Z, 0xFFFFFFFF, false},         {CButton::R, 0xFFFFFFFF, false},
    {CButton::L, 0xFFFFFFFF, false},         {CButton::A, 0xFFFFFFFF, false},
    {CButton::B, 0xFFFFFFFF, false},         {CButton::X, 0xFFFFFFFF, false},
    {CButton::Y, 0xFFFFFFFF, false},         {CButton::START, 0xFFFFFFFF, false},
};

KEEP_FUNC void GZ_readController() {
    sButtonsLastFrame = sButtons;
    sButtons = buttonStatus;
    sButtonsPressed = sButtons & (0xFFFF ^ sButtonsLastFrame);

    for (uint8_t idx = 0; idx < BUTTON_STATES; idx++) {
        buttonStates[idx].is_down = (buttonStates[idx].button & sButtons) != 0;
        if ((buttonStates[idx].button & sButtonsPressed) != 0) {
            buttonStates[idx].pressed_frame = cCt_getFrameCount() + 1;
        }
    }

    GZ_applyCheats();
    if (g_menuMgr->isOpen()) {
        uint16_t current_input = GZ_getButtonStatus();

        // prevent accidentally moving cursor down when opening menu
        if (!g_cursorEnabled) {
            if (current_input & CButton::DPAD_UP) {
                g_cursorEnabled = true;
            } else if (current_input & (CButton::L | CButton::R)) {
                sCursorEnableDelay = 0;
            } else if (sCursorEnableDelay < 1) {
                sCursorEnableDelay = 1;
            }

            if (sCursorEnableDelay >= 4) {
                g_cursorEnabled = true;
            } else if (sCursorEnableDelay > 0) {
                sCursorEnableDelay++;
            }
        }

        setGamepadButtons(0);
        setGamepadTrig(0);

        buttonStatus = 0x0;
        mPadButton.mRepeat = 0x0;
    } else {
        g_cursorEnabled = false;
        sCursorEnableDelay = 0;
        GZCmd_processInputs();
    }

    GZ_readZombieHoverInputs();
}

KEEP_FUNC bool GZ_getButtonPressed(int idx) {
    return buttonStates[idx].is_down;
}

KEEP_FUNC bool GZ_getButtonRepeat(int idx, uint16_t repeat_time) {
    // Needs to be signed due to delta sometimes being negative
    // which causes a subtle bug making held_down_long_enough
    // true when it shouldn't be
    s32 delta = cCt_getFrameCount() - buttonStates[idx].pressed_frame;

    auto just_clicked = delta == 0;
    auto held_down_long_enough = delta > REPEAT_DELAY;
    auto is_repeat_frame = held_down_long_enough && (delta % repeat_time == 0);
    auto down = GZ_getButtonPressed(idx);
    return down && (just_clicked || is_repeat_frame);
}

KEEP_FUNC bool GZ_getButtonRepeat(int idx) {
    return GZ_getButtonRepeat(idx, REPEAT_TIME);
}

KEEP_FUNC uint16_t GZ_getButtonStatus() {
    return buttonStatus;
}

KEEP_FUNC bool GZ_getButtonTrig(int idx) {
    auto delta = cCt_getFrameCount() - buttonStates[idx].pressed_frame;
    auto just_clicked = delta == 0;

    auto down = GZ_getButtonPressed(idx);
    return down && just_clicked;
}

KEEP_FUNC bool GZ_getButtonHold(int idx, int phase) {
    uint32_t delta = cCt_getFrameCount() - buttonStates[idx].pressed_frame;

    if (phase != POST_GAME_LOOP)
        delta++;

    return delta != 0 ? true : false;
}

KEEP_FUNC void GZ_getButtonPressCount(u8& i_pressCounter, int i_button, int i_gzButton) {
    if ((GZ_getButtonStatus() & i_button) && (buttonStates[i_gzButton].button & sButtonsPressed)) {
        i_pressCounter++;
    }
}

u8 arraySum(const u8 (&myArray)[WINDOW_LENGTH]) {
    u8 myArraySum = 0;
    for (int i = 0; i < WINDOW_LENGTH; i++) {
        myArraySum += myArray[i];
    }

    return myArraySum;
}

void updateButtonPressesInWindow(u8 (&buttonPressesInWindow)[WINDOW_LENGTH], const u32& current_frame,
                                 const u16& cButton, const int& gzButton) {
    u16 current_input = GZ_getButtonStatus();

    if ((current_input & cButton) && (buttonStates[gzButton].button & sButtonsPressed) != 0) {
        buttonPressesInWindow[current_frame % WINDOW_LENGTH] = 1;
    } else {
        buttonPressesInWindow[current_frame % WINDOW_LENGTH] = 0;
    }
}

void GZ_readZombieHoverInputs() {
    u32 zh_window_update_rate = 6;
    u32 current_frame = cCt_getFrameCount();

    if (current_frame % zh_window_update_rate == 0) {
        a_presses_per_window = arraySum(a_presses);
        b_presses_per_window = arraySum(b_presses);
    }

    updateButtonPressesInWindow(a_presses, current_frame, CButton::A, GZPad::A);
    updateButtonPressesInWindow(b_presses, current_frame, CButton::B, GZPad::B);
}

u8 GZ_getAPressesPerWindow() {
    return a_presses_per_window;
}

u8 GZ_getBPressesPerWindow() {
    return b_presses_per_window;
}