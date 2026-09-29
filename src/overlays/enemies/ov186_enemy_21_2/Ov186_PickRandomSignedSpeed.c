/* The `+ (v - v)` terms are the documented crack for RandNextScaled's copy artifact.
 * The second one needs its OWN local (`int r = …`): the ROM copies into a fresh register
 * (`add r1,r0,#0`), and inlining the expression makes mwcc copy in place (`add r0,r0,#0`)
 * and swap the multiply operands. */

#include "game/enemy_common.h"

extern int  RandNextScaled();
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov186_ChaseTargetOrReposition(void);

void Ov186_PickRandomSignedSpeed(int *self) {
    int v;
    int *obj = (int *)self[1];
    int sign;

    obj[10] = *(int *)(self[0] + 0x2c) * 0x1e / 20;
    Ov107_PostTagUpdate((Actor *)(*obj), 1, 1);
    sign = RandNextScaled(2) + (v - v) != 0 ? -1 : 1;
    {
        int r = RandNextScaled(0x101) + (v - v);
        obj[0x17] = r * sign;
    }
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), &Ov186_ChaseTargetOrReposition);
}
