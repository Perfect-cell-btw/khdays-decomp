/* AI step: once the actor is active (bit 0 of its flags at +0x60), rolls the 10% variant flag
 * (+0x38c), posts pose 1, makes the stored action (+0x1c9) pending and clears the step handler. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int node, int a, int b);
extern void SetIndexedSlot();

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov287_RollFlag38cCopySubStateThenAdvanceSlot(int this_) {
    int node = *(int *)(this_ + 4);
    if ((((struct hw60 *)(*(int *)node + 0x60))->lo & 1) == 0) return;
    *(int *)(*(int *)node + 0x38c) = RandNextScaled(0x64) < 0xa;
    Ov107_PostTagUpdate(*(int *)node, 1, 0);
    *(signed char *)(*(int *)node + 0x1c7) = *(signed char *)(*(int *)node + 0x1c9);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), 0);
}
