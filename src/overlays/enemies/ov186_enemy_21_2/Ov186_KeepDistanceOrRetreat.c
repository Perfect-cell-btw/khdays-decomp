/* The early-exit is written as the POSITIVE case (`dist <= 0x1000 || dist >= thresh`
 * -> set state 2 and return) so that block is the fall-through, which is where the ROM
 * has it. Writing it as `if (in range) { rand } else { state2 }` emits the two blocks
 * the other way round.
 * Ov186_LookAtQuat_2 takes THREE arguments; Ghidra shows a fourth (leftover in r3). */

#include "game/engine.h"

extern int  Ov107_FindNearestObject(int obj, int *out);
extern void SetIndexedSlot(int self, int index, void *cb);
extern int  FX_Sqrt(int x);
extern void Ov186_LookAtQuat_2();
extern void ScaleVec3Fx12();
extern char data_02042258[];

void Ov186_KeepDistanceOrRetreat(int self) {
    int *obj = *(int **)(self + 4);
    int dist;
    int owner, target;

    target = obj[1] = Ov107_FindNearestObject(*obj, &dist);
    if (target == 0) {
        *(signed char *)(*obj + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    obj[10] = *(int *)(*(int *)self + 0x2c) * 0x1e / 20;
    owner = *obj;
    target = obj[1];
    dist = FX_Sqrt(dist) - (*(int *)(target + 0x80) + *(int *)(owner + 0x80));
    Ov186_LookAtQuat_2((int)obj, obj + 6, dist);
    Vec3TransformViaTempMtx(obj + 0xb, obj + 2, data_02042258);
    ScaleVec3Fx12(0x100, obj + 0xb, obj + 0xb);
    if (dist <= 0x1000 || dist >= *(int *)(*obj + 0x2d8)) {
        *(signed char *)(*obj + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    if (obj[0x10] > 0) {
        return;
    }
    {
        int lo = *(int *)(*obj + 0x224);
        int range = *(int *)(*obj + 0x228) - lo;
        if (range < 0) {
            range = -range;
        }
        obj[0x10] = lo + RandNextScaled(range + 1);
    }
    *(signed char *)(*obj + 0x1c7) = 6;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
}
