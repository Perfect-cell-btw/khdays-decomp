/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov204_GuardField28Pose10ClearAdvance();

void Ov204_SetPose9ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 9, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov204_GuardField28Pose10ClearAdvance);
}
