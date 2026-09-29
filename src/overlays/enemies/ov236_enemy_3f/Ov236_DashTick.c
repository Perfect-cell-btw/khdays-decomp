/* Dash tick: the +0x14 rate is 30 x frame step / 50, the +0x28 timer counts the frame step
 * down, and the +0x18 step is rebuilt from the actor's +0xa0 pose transformed by the +0x3ac
 * sub-object's steer vector (scaled by its factor). Once the +4 child's +0xad byte clears, pose
 * 0x14 plays (looping), the sub-object plays 7 and the node moves to 020d159c. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *src, void *w);
extern void ScaleVec3Fx12(int scale, void *in, void *out);
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov236_DashSteerTick(void);

void Ov236_DashTick(int *self) {
    int *state = (int *)self[1];
    int w[3];
    int factor;

    state[5] = *(int *)(self[0] + 0x2c) * 30 / 50;
    state[0xa] -= *(int *)(self[0] + 0x2c);
    factor = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x3ac), (VecFx32 *)w);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), w);
    ScaleVec3Fx12(factor, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x14, 1);
    Ov107_StartAnim(*(int *)(*state + 0x3ac), 7, 1);
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov236_DashSteerTick);
}
