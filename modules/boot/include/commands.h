#pragma once
#include "libtww/include/dolphin/gctypes.h"


// WARNING: adding an entry to this list shifts the save data 
// and requires a save version bump
enum Commands {
    CMD_STORE_POSITION,
    CMD_LOAD_POSITION,
    CMD_MOON_JUMP,
    CMD_STORAGE,
    CMD_NORMAL_COLLISION,
    CMD_CHEST_STORAGE,
    CMD_DOOR_CANCEL,
    CMD_QUARTER_HEART,
    CMD_FAST_MOVEMENT,
    CMD_UPCHARGE,
    CMD_AREA_RELOAD,
    CMD_REFILL_HEALTH,
    CMD_REFILL_MAGIC,
    CMD_FRAME_ADVANCE,

    CMD_AMNT
};

extern bool g_commandStates[CMD_AMNT];

struct Command {
    bool& active;
    uint16_t buttons;
    void (*command)();
};

void GZCmd_processInputs();
void GZCmd_enable(int idx);
void GZCmd_disable(int idx);

f32 getWaterSpeed();
void setWaterSpeed(f32 speedNum);
f32 getLandSpeed();
void setLandSpeed(f32 speedNum);