/*
 * Ov211_RebuildSteerAndGate -- x3 (ov210/211/282). AI-state tick: rebuild the steer vector, and once the
 * sub-node at state[3] goes idle, transition.
 * factor = 020c9f48(*(*state+0x3b8), &w); build state[5..7] from *state+0xa0 (0202f384) and scale it
 * by factor (01ffa724). While the sub-node byte *(u8)state[3] is still set, return; once idle mark
 * *(*state+0x1c7)=0xf and hand off via 0203c634 (cb=0).
 */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *src, void *w);
extern void ScaleVec3Fx12(int scale, void *in, void *out);
extern void SetIndexedSlot(int self, int idx, int cb);

void Ov211_RebuildSteerAndGate(int *self) {
    int *state = (int *)self[1];
    int w[3];
    int factor;

    factor = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x3b8), (VecFx32 *)w);
    Vec3TransformViaTempMtx((void *)(state + 5), (void *)(*state + 0xa0), w);
    ScaleVec3Fx12(factor, (void *)(state + 5), (void *)(state + 5));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    *(char *)(*state + 0x1c7) = 0xf;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), 0);
}
