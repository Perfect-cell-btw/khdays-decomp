/* AI step: once the gate byte is clear, posts pose 2 and installs the seek-and-steer step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov164_stSeekTargetSteer();

void Ov164_Pose2GuardField58Advance(int this_) {
    int n = *(int *)(this_ + 4);
    if (*(unsigned char *)*(int *)(n + 0x58)) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)n), 2, 1);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov164_stSeekTargetSteer);
}
