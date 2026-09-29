/* State step: posts tag 1, starts a random timer and installs the hover step. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot();
extern void Ov173_HoverBobTick();

void Ov173_SetPoseAndRandomTimer(int this_) {
    int node = *(int *)(this_ + 4);
    Ov107_PostTagUpdate(*(int *)node, 1, 1);
    *(int *)(node + 0x54) = RandNextScaled(0x15) + 0x14;
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov173_HoverBobTick);
}
