/* Countdown step: counts the timer down by the owner's frame step; at zero posts pose 5 and
 * installs the slot-scan step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov145_stateScanSlotRoundRobin();

void Ov145_CountdownTimer38ThenPose5(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int v = *(int *)(b + 0x38) - *(int *)(a + 0x2c);
    *(int *)(b + 0x38) = v;
    if (v > 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)b), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov145_stateScanSlotRoundRobin);
}
