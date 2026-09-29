/* AI step: sets the velocity from the action resource's offset and scale in the actor's frame; when
 * the model's animation ends posts pose 9, clears flag 0x40 in the high byte of the actor's flags
 * and installs the delay step. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(int a, int b, void *c);
extern void ScaleVec3Fx12(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov190_AiDelayThenAnim10(void);

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov190_ApplyAimThenClearFlag(int *self) {
    int v[3];
    int *s = (int *)self[1];
    int r = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*s + 0x3c0), (VecFx32 *)v);
    Vec3TransformViaTempMtx((int)s + 0x20, *s + 0xa0, v);
    ScaleVec3Fx12(r, (int)s + 0x20, (int)s + 0x20);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*s), 9, 1);
    ((struct hw60 *)(*s + 0x60))->hi &= ~0x40;
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov190_AiDelayThenAnim10);
}
