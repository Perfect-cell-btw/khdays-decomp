/* State step: posts tag 1, starts a random timer and installs the hover step. */

#include "game/enemy_common.h"

extern int RandNextScaled();
extern void SetIndexedSlot();
extern void Ov174_HoverBobTick();

void Ov174_SetPoseAndRandomTimer(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)node), 1, 1);
    *(int *)(node + 0x54) = RandNextScaled(0x15) + 0x14;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov174_HoverBobTick);
}
