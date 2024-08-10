#ifndef TWWGZ_ACTOR_MOVE_LISTENER_H
#define TWWGZ_ACTOR_MOVE_LISTENER_H

#include "events/listener_base.h"
#include "libtww/include/dolphin/gctypes.h"
#include "libtww/include/f_op/f_op_actor_iter.h"

typedef enum ActorMoveType {
    ACTORMOVE_POS,
    ACTORMOVE_POS_YAW,
} ActorMoveType;

typedef struct {
    f32 x, y, z;
    s16 yaw;
} ActorMoveArgs;


typedef void(ActorMoveCallback_t)();

typedef events::ListenerBase<ActorMoveCallback_t> ActorMoveListener;

extern ActorMoveListener* g_ActorMoveListener;

void ActorMove_Request(s16 procName, ActorMoveArgs* args, ActorMoveType type);

#endif
