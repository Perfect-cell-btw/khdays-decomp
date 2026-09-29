/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov130_PrepSubState4IfChildIdle();

void Ov130_SetPose1ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 1, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov130_PrepSubState4IfChildIdle);
}
