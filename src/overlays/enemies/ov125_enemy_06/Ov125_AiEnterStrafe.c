/*
 * Ov125_AiEnterStrafe -- x3. AI-state tick: fire, roll a random strafe sign, dispatch.
 * Fire attack 1 (020c9264, flag 1). state[0x1e] = RandNextScaled(2) ? -1 : 1 (random sign);
 * state[0xb] = 0. Hand off to the 020cf828 state.
 */

#include "game/enemy_common.h"

extern int  RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov125_CircleTick(void);

void Ov125_AiEnterStrafe(int *self) {
    int *state = (int *)self[1];
    int v;

    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    /* +(v-v) forces `adds r0,r0,#0` (rand result copied+tested); +0 would fold away */
    state[0x1e] = (RandNextScaled(2) + (v - v)) != 0 ? -1 : 1;
    state[0xb] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov125_CircleTick);
}
