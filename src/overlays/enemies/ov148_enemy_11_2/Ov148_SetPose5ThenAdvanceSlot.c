/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov148_CopyScaleVec3ThenAdvanceSlot();

void Ov148_SetPose5ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 5, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov148_CopyScaleVec3ThenAdvanceSlot);
}
