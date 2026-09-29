/* Unless the predicate holds, kick anim 6, clear +0x28/+0x42/+0x40, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov245_AnimGate(int);
extern int Ov245_WaitTick(int);
void Ov245_AiWaitStart(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (Ov245_AnimGate(*(int *)owner) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 6, 0);
    *(int *)(owner + 0x28) = 0;
    *(signed char *)(owner + 0x42) = 0;
    *(signed char *)(owner + 0x40) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_WaitTick);
}
