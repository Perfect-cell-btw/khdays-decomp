/*
 * Ov185_SeedRandomStrafe -- x3 (ov185/186/187). AI-state tick: seed a randomized strafe and dispatch.
 * state[0xa] = owner_delta*30/10. Fire attack 1 (020c9264, flag 1). Roll a random sign
 * state[0x17] = RandNextScaled(2) ? -1 : 1, and a random duration state[0x18] = RandNextScaled(0x101)
 * + 0x200. Hand off to the 020cefa8 state.
 */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int  RandNextScaled();  /* K&R decl: needed for the rand `+ (v - v)` copy artifact */
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov185_CircleStrafe_Step(void);

void Ov185_SeedRandomStrafe(int *self) {
    int *state = (int *)self[1];
    int v = *(int *)(*self + 0x2c);

    state[0xa] = v * 0x1e / 10;
    Ov107_PostTagUpdate(*state, 1, 1);
    /* +(v-v) forces `adds r0,r0,#0` (rand result copied+tested); +0 would fold away */
    state[0x17] = (RandNextScaled(2) + (v - v)) != 0 ? -1 : 1;
    state[0x18] = RandNextScaled(0x101) + 0x200;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov185_CircleStrafe_Step);
}
