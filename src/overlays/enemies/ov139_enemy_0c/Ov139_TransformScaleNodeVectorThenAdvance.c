#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };

extern void Vec3TransformViaTempMtx(int dst, int mtx, int *v);
extern void ScaleVec3Fx12(int s, int dst, int src);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov139_Action6IfHitFlagsSet(void);

// Sample the linked object's transform (obj[0x390]) into a temp, rotate the node
// vector (node+0x14) by it and scale by the returned factor. If the factor is 0
// the move is complete: clear hw60 flag 0x40 and advance the sub-state.
void Ov139_TransformScaleNodeVectorThenAdvance(int *this)
{
    int node = this[1];
    int tmp[3];
    int scale = Ov107_ActionResource_GetOffsetAndScale(*(int *)(*(int *)node + 0x390), (VecFx32 *)tmp);
    Vec3TransformViaTempMtx(node + 0x14, *(int *)node + 0xa0, tmp);
    ScaleVec3Fx12(scale, node + 0x14, node + 0x14);
    if (scale != 0) {
        return;
    }
    ((struct hw60 *)(*(int *)node + 0x60))->hi &= ~0x40;
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov139_Action6IfHitFlagsSet);
}
