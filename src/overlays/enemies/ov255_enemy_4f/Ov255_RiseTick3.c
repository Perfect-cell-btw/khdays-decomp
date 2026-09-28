/* Glide tick of an ov255 state: the +0x50 timer accumulates the owner's rate and the +0x5c path
 * point is resolved (Ov255_SteerToTarget) into the +0x10 step. Once the +0xc idle byte clears,
 * animation 0x1f plays looped, the +0x3a4 part plays motion 0x1a and the tick hands over to
 * Ov255_RiseTick4. */

#include "nitro/fx_types.h"

extern void Ov255_SteerToTarget(int *state, int point, VecFx32 *dir, int *speed);
extern void ScaleVec3Fx12(int scale, const VecFx32 *v, VecFx32 *out);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_RiseTick4(int *node);

void Ov255_RiseTick3(int *node)
{
    int *state = (int *)node[1];
    VecFx32 dir;
    int speed;

    state[0x14] += *(int *)(node[0] + 0x2c);
    Ov255_SteerToTarget(state, state[0x17], &dir, &speed);
    ScaleVec3Fx12(speed, &dir, (VecFx32 *)(state + 4));
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0x1f, 1);
    Ov107_StartAnim(*(int *)(*state + 0x3a4), 0x1a, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_RiseTick4);
}
