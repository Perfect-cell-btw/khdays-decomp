/*
 * Ov271_SeedRandomStrafeSign -- x3. AI-state tick: fire, roll a random strafe sign, dispatch.
 * Fire attack 1 (020c9264, flag 1). state[0x29] = RandNextScaled(2) ? -1 : 1 (random sign);
 * state[0x14] = 0. Hand off to the 020cf828 state.
 */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int  RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov271_CircleTick(void);

void Ov271_SeedRandomStrafeSign(int *self) {
    int *state = (int *)self[1];
    int v;

    Ov107_PostTagUpdate(*state, 1, 1);
    /* +(v-v) forces `adds r0,r0,#0` (rand result copied+tested); +0 would fold away */
    state[0x29] = (RandNextScaled(2) + (v - v)) != 0 ? -1 : 1;
    state[0x14] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov271_CircleTick);
}
