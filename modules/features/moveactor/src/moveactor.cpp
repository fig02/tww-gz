#include "features/moveactor/include/moveactor.h"
#include <cstdio>
#include "font.h"
#include "global_data.h"
#include "libtww/include/MSL_C/math.h"
#include "settings.h"
#include "libtww/include/JSystem/JUtility/JUTGamePad.h"
//#include "libtp_c/include/f_op/f_op_draw_tag.h"
//#include "libtww/include/m_Do/m_Re_controller_pad.h"
#include "rels/include/defines.h"
#include "libtww/include/d/d_meter.h"
#include "libtww/include/d/d_procname.h"
#include "libtww/include/d/a/d_a_player_main.h"

#define ROTATION_SPEED (30)
#define ROTATION_FAST_SPEED (80)
#define ROTATION_VERY_FAST_SPEED (800)
#define CAM_SPEED (1.0)
#define CAM_FAST_SPEED (2.5)
#define CAM_VERY_FAST_SPEED (10.0)
#define DIST_FROM_ACTOR (600)

#define CONTROL_Y (mPadStatus.stick_y)
#define CONTROL_X (mPadStatus.stick_x)
#define VERTICAL_DISPLACEMENT (mPadStatus.substick_y)
#define HORIZONTAL_DISPLACEMENT -(mPadStatus.substick_x)
#define SPEED_PREDICATE_1 (mPadButton.mButton & CButton::Z)
#define SPEED_PREDICATE_2 (mPadButton.mButton & CButton::R)
#define LOCK_CAMERA (mPadButton.mButton & CButton::L)

#define WHITE_RGBA 0xFFFFFFFF
#define LINE_X_OFFSET 20.0f

namespace MoveActor {

double pitch = 0.0;
double yaw = 0.0;
float angle = 0.0f;
bool event_halt = false;

void move(fopAc_ac_c* actor) {
    // Fetch the camera position and target
    Vec& cam_target = g_dComIfG_gameInfo.play.mCameraInfo->mCameraTarget;
    Vec& cam_pos = g_dComIfG_gameInfo.play.mCameraInfo->mCameraPos;

    // Fetch the actor position and angles
    cXyz& actor_pos = actor->current.pos;
    s16& actor_horizontal_angle = actor->shape_angle.y;
    s16& actor_verticle_angle = actor->shape_angle.x;

    // Set Link momentum to 0
    cXyz tmp(0.0f, 0.0f, 0.0f);
    dComIfGp_getPlayer(0)->speed = tmp;

    if (!LOCK_CAMERA) {
        angle = (float)actor_horizontal_angle / 65536.f * (2 * M_PI);
    }

    // Fix Camera behind link
    cam_target.x = actor_pos.x;
    cam_target.y = actor_pos.y + 200.f;
    cam_target.z = actor_pos.z;
    cam_pos.z = actor_pos.z - DIST_FROM_ACTOR * cos(angle);
    cam_pos.x = actor_pos.x - DIST_FROM_ACTOR * sin(angle);
    cam_pos.y = actor_pos.y + 200.f;

    // Calculate the pitch and yaw
    yaw = atan2(cam_target.z - cam_pos.z, cam_target.x - cam_pos.x);
    double horizontal = sqrtf((cam_target.x - cam_pos.x) * (cam_target.x - cam_pos.x) +
                              (cam_target.z - cam_pos.z) * (cam_target.z - cam_pos.z));
    pitch = atan2(cam_target.y - cam_pos.y, horizontal);

    // Calculate the translation
    double dy = LOCK_CAMERA ? 0.0f : VERTICAL_DISPLACEMENT;
    double dx = CONTROL_Y * cos(yaw) * cos(pitch) - CONTROL_X * sin(yaw);
    double dz = CONTROL_Y * sin(yaw) * cos(pitch) + CONTROL_X * cos(yaw);

    auto move_speed =
        SPEED_PREDICATE_1 != 0 ? SPEED_PREDICATE_2 != 0 ? CAM_VERY_FAST_SPEED : CAM_FAST_SPEED : CAM_SPEED;
    auto cam_speed = SPEED_PREDICATE_1 != 0 ? SPEED_PREDICATE_2 != 0 ? ROTATION_VERY_FAST_SPEED : ROTATION_FAST_SPEED :
                                              ROTATION_SPEED;

    // Apply the translation with a speed factor
    actor_pos.x += move_speed * dx;
    actor_pos.y += move_speed * dy;
    actor_pos.z += move_speed * dz;

    // Change facing angle with c stick
    if (LOCK_CAMERA) {
        actor_verticle_angle -= -VERTICAL_DISPLACEMENT * cam_speed;
        actor_horizontal_angle -= -HORIZONTAL_DISPLACEMENT * cam_speed;
    } else {
        actor_horizontal_angle -= HORIZONTAL_DISPLACEMENT * cam_speed;
    }
}

KEEP_FUNC void execute() {
    daPy_lk_c* player_p = (daPy_lk_c*)dComIfGp_getPlayer(0);

    if (g_actorViewEnabled || g_moveLinkEnabled) {
        // Hide HUD
        g_meterHIO.field_0x18 = 0.0f;

        // Lock the camera to allow for its movement
        dComIfGp_getPEvtManager()->mCameraPlay = 1;

        // Special case for Link (this needs to be refactored to be more generic)
        if (player_p && (g_moveLinkEnabled || g_currentActor->mBase.mProcName == PROC_PLAYER)) {
            player_p->mAcch.SetGrndNone();
            player_p->mAcch.SetRoofNone();
            player_p->mAcch.OnLineCheckNone();

            g_dComIfG_gameInfo.play.mEvtCtrl.mbEndProc = true;
            event_halt = true;

            move(dComIfGp_getPlayer(0));
        } else {
            g_dComIfG_gameInfo.play.mEvtCtrl.mbEndProc = false;
            event_halt = false;

            move(g_currentActor);
        }
    } else {
        if (event_halt) {
            if (player_p) {
                player_p->mAcch.ClrGrndNone();
                player_p->mAcch.ClrWallNone();
                player_p->mAcch.ClrRoofNone();
                player_p->mAcch.OffLineCheckNone();
            }

            g_dComIfG_gameInfo.play.mEvtCtrl.mbEndProc = false;
            event_halt = false;

            dComIfGp_getPEvtManager()->mCameraPlay = 0;
            g_meterHIO.field_0x18 = 0.0f;
        }
    }
}
}  // namespace MoveActor