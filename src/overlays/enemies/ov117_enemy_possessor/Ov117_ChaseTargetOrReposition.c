/* Two comparison forms matter here, both for the same reason (the ROM's constant is an
 * ARM immediate and mine was not): `obj[0x10] <= 0` not `< 1`, and `dist <= 0x2000`
 * not `< 0x2001`.
 * Ov117_LookAtQuat takes THREE arguments -- Ghidra shows a fourth, which is the
 * leftover in r3. Passing it costs a callee-saved register and 32 B.
 * `target = obj[1] = f(...)` in that order: the ROM stores the raw r0. */

#include "game/engine.h"

extern int  Ov107_FindNearestObject(int obj, int *out);
extern int  FX_Sqrt(int x);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov117_LookAtQuat();
extern void VEC_CrossProduct();
extern void ScaleVec3Fx12();
extern char data_02042258[];
extern char data_02042264[];

void Ov117_ChaseTargetOrReposition(int self) {
    int *obj = *(int **)(self + 4);
    int dist;
    int owner;
    int target;

    target = obj[1] = Ov107_FindNearestObject(*obj, &dist);
    if (target == 0) {
        return;
    }
    owner = *obj;
    dist = FX_Sqrt(dist) - (*(int *)(target + 0x80) + *(int *)(owner + 0x80));
    owner = *obj;
    if (dist > *(int *)(owner + 0x2d8)) {
        return;
    }
    if (obj[0x10] <= 0) {
        int lo = *(int *)(owner + 0x224);
        int range = *(int *)(owner + 0x228) - lo;
        if (range < 0) {
            range = -range;
        }
        obj[0x10] = lo + RandNextScaled(range + 1);
        *(signed char *)(*obj + 0x1c7) = 6;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    if (dist <= 0x2000) {
        Ov117_LookAtQuat((int)obj, obj + 6, dist);
        Vec3TransformViaTempMtx(obj + 0xb, obj + 2, data_02042258);
        VEC_CrossProduct(obj + 0xb, data_02042264, obj + 0xb);
        ScaleVec3Fx12(obj[0x17], obj + 0xb, obj + 0xb);
        return;
    }
    *(signed char *)(owner + 0x1c7) = 4;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
}
