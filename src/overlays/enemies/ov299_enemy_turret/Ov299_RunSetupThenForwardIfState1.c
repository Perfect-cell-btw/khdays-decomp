/* Moves the actor's node and, in state 1, aims it at the target. */

#include "game/enemy_common.h"

extern void Ov299_AimAtTarget();

void Ov299_RunSetupThenForwardIfState1(int this_, int arg1, int arg2, int arg3) {
    Ov107_MoveNodeAndRelayout((Actor *)this_, (VecFx32 *)arg1);
    if (*(int *)(this_ + 0x50) != 1) return;
    Ov299_AimAtTarget(*(int *)(this_ + 0x214), arg2, arg3);
}
