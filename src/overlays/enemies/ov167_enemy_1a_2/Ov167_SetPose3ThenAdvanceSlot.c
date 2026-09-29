/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov167_AiDecelUntilAnimEnd();

void Ov167_SetPose3ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 3, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov167_AiDecelUntilAnimEnd);
}
