/*
 * Ov282_SeedRandomTimer -- x3. AI-state tick: fire, seed a random timer, dispatch.
 * state[0x14] = 0. Fire attack 1 (020c9264, flag 1). state[0xc] = RandNextScaled(0xa01) (random
 * duration); state[0xb] = 0 (elapsed); state[0x1a] = 0. Hand off to the 020d0d24 state.
 */

#include "game/enemy_common.h"

extern int  RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov282_AiPickMove(void);

void Ov282_SeedRandomTimer(int *self) {
    int *state = (int *)self[1];
    int v;

    state[0x14] = 0;
    Ov107_PostTagUpdate((Actor *)(*state), 1, 1);
    /* +(v-v) forces the rand result to be copied through `add r0,r0,#0` before the store */
    state[0xc] = RandNextScaled(0xa01) + (v - v);
    state[0xb] = 0;
    state[0x1a] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov282_AiPickMove);
}
