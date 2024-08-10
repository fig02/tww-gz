#include "events/actor_move_listener.h"
#include "libtww/include/f_op/f_op_actor.h"
#include "libtww/include/f_op/f_op_actor_mng.h"
#include "rels/include/defines.h"

KEEP_VAR ActorMoveListener* g_ActorMoveListener = nullptr;


void ActorMove_Callback(s16 procName, ActorMoveArgs* args, ActorMoveType type) {
    fopAc_ac_c* actor = fopAcM_SearchByName(procName);

    // If actor is NULL at this point, the actor doesn't exist yet and may still be creating
    if (actor != nullptr) {
        switch (type) {
            case ACTORMOVE_POS_YAW:
                actor->current.angle.y = actor->shape_angle.y = args->yaw;
                // FALLTHROUGH
            case ACTORMOVE_POS:
                    actor->current.pos.set(args->x, args->y, args->z);

        }
    }
}

void ActorMove_Request(s16 procName, ActorMoveArgs* args, ActorMoveType type) {
    auto callback = [procName, args, type](){
        ActorMove_Callback(procName, args, type);
    };

    g_ActorMoveListener->addListener((ActorMoveCallback_t*)&callback);
}