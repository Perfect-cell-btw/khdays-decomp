/* Per-frame step of the launch-at-target action. Re-acquires the lock-on target; a null target ends
 * the action. Otherwise it takes the vector from the actor to the target and normalises it in
 * place, which also yields the distance, clamps that to 0x8000 and runs the aim helper, then resets
 * the vertical component of the advance vector to -0x200. The launch half only runs while bit 0 of
 * the actor flag byte at 0x17a is set. It flattens the delta on Y, normalises it and scales it by
 * the clamped distance over thirty to get the launch velocity, clears the timer, latches the
 * animation id and sets the proximity flag before handing the node to the follow-up action. The two
 * components of the flattened delta are read into locals before any of the stores: that is what
 * keeps both loads ahead of the write-back, which is the order the ROM uses. */

#include "game/actor.h"

typedef struct { unsigned char b0 : 1; } Bit0;

extern int  Ov107_FindNearestObject(int obj, int flag);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void VEC_Subtract();
extern int  VEC_Normalize();
extern void Ov118_LookAtQuat();
extern void ScaleVec3Fx12();
extern void Ov118_OrbitStep(void);

void Ov118_AimAtTarget(int self) {
    int *obj = *(int **)(self + 4);
    int v[3];
    int n;
    int target = Ov107_FindNearestObject(*obj, 0);

    obj[1] = target;
    if (target == 0) {
        *(signed char *)(*obj + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    VEC_Subtract(target + 400, *obj + 0xb0, v);
    n = VEC_Normalize(v, v);
    if (n > 0x8000) {
        n = 0x8000;
    }
    Ov118_LookAtQuat((int)obj, obj + 6);
    obj[0xc] = -0x200;
    if (((Bit0 *)(*obj + 0x17a))->b0) {
        Actor *state = (Actor *)obj;
        int z = v[2];
        state->camera[0] = v[0];
        state->camera[1] = 0;
        state->camera[2] = z;
        VEC_Normalize(obj + 0x19, obj + 0x19);
        ScaleVec3Fx12(n / 30, obj + 0x19, obj + 0x19);
        obj[0x18] = 0;
        obj[0x1c] = *(int *)(obj[0x11] + 4);
        {
            unsigned short w = *(unsigned short *)(*obj + 0x60);
            *(unsigned short *)(*obj + 0x60) =
                (unsigned short)((w & ~0xff00)
                                 | (((((unsigned int)w << 0x10) >> 0x18 | 2) << 0x18) >> 0x10));
        }
        SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov118_OrbitStep);
    }
}
