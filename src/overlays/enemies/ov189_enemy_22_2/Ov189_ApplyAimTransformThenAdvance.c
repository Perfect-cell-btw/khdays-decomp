/* AI step: sets the velocity from the action resource's offset and scale in the actor's frame; when
 * the model's animation ends posts pose 8, starts the action resource's animation and installs the
 * next aimed step. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(int a, int b, void *c);
extern void ScaleVec3Fx12(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov189_ApplyAimThenClearFlag(void);

void Ov189_ApplyAimTransformThenAdvance(int *self) {
    int v[3];
    int *s = (int *)self[1];
    int r = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*s + 0x3c0), (VecFx32 *)v);
    Vec3TransformViaTempMtx((int)s + 0x20, *s + 0xa0, v);
    ScaleVec3Fx12(r, (int)s + 0x20, (int)s + 0x20);
    if (*(unsigned char *)(s[1] + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*s), 8, 0);
    Ov107_StartAnim(*(int *)(*s + 0x3c0), 2, 0);
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), (void *)&Ov189_ApplyAimThenClearFlag);
}
