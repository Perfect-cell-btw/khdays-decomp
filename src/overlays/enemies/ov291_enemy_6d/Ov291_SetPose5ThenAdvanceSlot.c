/* AI step: posts pose 5 and continues with the wrap counter. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov291_AdvanceWrapCounterThenSubState3();

void Ov291_SetPose5ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov291_AdvanceWrapCounterThenSubState3);
}
