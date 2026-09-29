/* Ov245_RiseTick -- rise tick: the state's +0x14 height follows +0x20 and the +0x3c limit is
 * 5.0; once the node's +8 origin plus that height reaches the limit plus 15.0 the actor's +0x438 child is
 * released (020d488c), pose 7 plays, the +0x4c8 anchor's motion 1 starts and the node moves to
 * 020ce560. */

#include "game/enemy_common.h"

extern void Ov245_ResetVelocity(int child);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov245_LandingTick(void);

void Ov245_RiseTick(int *node) {
    int *state = (int *)node[1];

    state[5] = state[8];
    state[0xf] = 0x5000;
    if (*(int *)(state[2] + 8) + state[5] < state[0xf] + 0xf000) {
        return;
    }
    Ov245_ResetVelocity(*(int *)(*state + 0x438));
    Ov107_PostTagUpdate((Actor *)(*state), 7, 0);
    Ov107_StartAnim(*(int *)(*state + 0x4c8), 1, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov245_LandingTick);
}
