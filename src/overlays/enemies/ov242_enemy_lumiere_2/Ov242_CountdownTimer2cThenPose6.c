/* AI step: counts the timer down and, when the model's animation ends, posts pose 6 and installs
 * the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov242_ConfigSubStateThenAdvanceSlot();

void Ov242_CountdownTimer2cThenPose6(int this_) {
    int a = *(int *)this_;
    int b = *(int *)(this_ + 4);
    int obj;
    *(int *)(b + 0x2c) = *(int *)(b + 0x2c) - *(int *)(a + 0x2c);
    obj = *(int *)b;
    if (*(unsigned char *)(*(int *)(obj + 0x384) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)obj, 6, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov242_ConfigSubStateThenAdvanceSlot);
}
