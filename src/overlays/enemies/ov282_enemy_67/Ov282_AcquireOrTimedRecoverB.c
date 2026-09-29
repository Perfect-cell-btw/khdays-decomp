/*
 * Ov282_AcquireOrTimedRecoverB -- x3 (ov210/211/282). AI-state tick: acquire target, else timed recovery.
 * Twin of Ov210_AcquireOrTimedRecover (020d2ad8) with attack 0xf and the 020d2e78 continuation.
 */

#include "game/enemy_common.h"
#include "game/engine.h"

extern int  Ov107_FindNearestObject(int obj, int flag);
extern void SetIndexedSlot(int self, int idx, int cb);
extern void Ov282_StrafeSameTargetNeg(void);

void Ov282_AcquireOrTimedRecoverB(int *self) {
    int *state = (int *)self[1];
    int target = Ov107_FindNearestObject(*state, 0);
    state[4] = target;
    if (target == 0) {
        *(char *)(*state + 0x1c7) = 2;
        SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0xf, 0);
    state[0x14] = 0x3000;
    state[0xc] = RandNextScaled(0x1001) + 0x1000;
    state[0xb] = 0;
    SetIndexedSlot((int)self, *(signed char *)((int)self + 0x20), (int)&Ov282_StrafeSameTargetNeg);
}
