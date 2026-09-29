/*
 * Ov282_RebuildSteerFireChild -- x3 (ov210/211/282). AI-state tick: rebuild the steer vector; once the
 * sub-node at state[3] goes idle, fire and transition.
 * factor = 020c9f48(*(*state+0x3b8),&w); build state[5..7] from *state+0xa0 (0202f384), scale by
 * factor (01ffa724). While *(u8)state[3] set, return; once idle fire attack 0xc (flag 1), clear
 * state[0xb], kick the child (020c9ee8(*(*state+0x3b8),1,1)) and hand off to the 020d26e0 state.
 */
extern int  Ov107_ActionResource_GetOffsetAndScale(int obj, void *out);
extern void Vec3TransformViaTempMtx(void *dst, void *src, void *w);
extern void ScaleVec3Fx12(int scale, void *in, void *out);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int obj, int a, int b);
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov282_AimCloseInRange(void);

void Ov282_RebuildSteerFireChild(int *self) {
    int *state = (int *)self[1];
    int w[3];
    int factor;

    factor = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x3b8), w);
    Vec3TransformViaTempMtx((void *)(state + 5), (void *)(*state + 0xa0), w);
    ScaleVec3Fx12(factor, (void *)(state + 5), (void *)(state + 5));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0xc, 1);
    state[0xb] = 0;
    Ov107_StartAnim(*(int *)(*state + 0x3b8), 1, 1);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov282_AimCloseInRange);
}
