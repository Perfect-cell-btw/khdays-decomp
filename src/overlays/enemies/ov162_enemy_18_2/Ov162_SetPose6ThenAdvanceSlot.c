/* Posts a tag update for a pose, then installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov162_BeginRecoil();

void Ov162_SetPose6ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 6, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov162_BeginRecoil);
}
