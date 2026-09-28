/* Lunge tick: rebuilds the +0x18 step from the actor's +0xa0 pose transformed by the +0x3ac
 * sub-object's steer vector (scaled by its factor); once the +4 child's +0xad byte clears, pose
 * 4 (or 2 when bit 0 of +0x52 is clear) is requested and the node dispatches null. */
struct Bits52 { unsigned char b0 : 1; };
extern int  Ov107_ActionResource_GetOffsetAndScale(int obj, void *out);
extern void Vec3TransformViaTempMtx(void *dst, void *src, void *w);
extern void ScaleVec3Fx12(int scale, void *in, void *out);
extern void SetIndexedSlot(int self, int idx, int cb);

void Ov236_LungeTick(int *self) {
    int *state = (int *)self[1];
    int w[3];
    int factor;

    factor = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x3ac), w);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), w);
    ScaleVec3Fx12(factor, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    if (((struct Bits52 *)((char *)state + 0x52))->b0 != 0) {
        *(char *)(*state + 0x1c7) = 4;
    } else {
        *(char *)(*state + 0x1c7) = 2;
    }
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), 0);
}
