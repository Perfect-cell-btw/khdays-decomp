/* AI step: computes the path velocity from the action resource and heading and, when the action
 * ends, posts pose 2 and continues with following the path. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx();
extern void ScaleVec3Fx12();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov291_PathFollowTick(void);
void Ov291_stateTransformScaleTimer(int *node, int p2, int p3, int param_4) {
    int *state = (int *)node[1];
    int buf[3];
    int uStack_14 = param_4;
    int scale = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*state + 0x394), (VecFx32 *)buf);
    Vec3TransformViaTempMtx(buf, *state + 0xa0, buf);
    ScaleVec3Fx12(scale, buf, state + 4);
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[7] = v / 25;
    }
    if (*(unsigned char *)state[8] == 0) {
        Ov107_PostTagUpdate((Actor *)(*state), 2, 1);
        Ov107_StartAnim(*(int *)(*state + 0x394), 1, 1);
        *(signed char *)((char *)state + 0x28) = 0;
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov291_PathFollowTick);
    }
}
