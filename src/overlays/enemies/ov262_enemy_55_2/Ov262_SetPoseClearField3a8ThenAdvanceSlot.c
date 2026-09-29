/* State step: posts pose 2, drops the grabbed object and installs the float-height step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov262_FloatHeightTick();

void Ov262_SetPoseClearField3a8ThenAdvanceSlot(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 2, 1);
    *(int *)(*(int *)node + 0x3a8) = 0;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov262_FloatHeightTick);
}
