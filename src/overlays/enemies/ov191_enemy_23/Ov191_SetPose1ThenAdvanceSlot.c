/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov191_ChaseTick();

void Ov191_SetPose1ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 1, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov191_ChaseTick);
}
