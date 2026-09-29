/* Push animation params (4, 0) to the sprite, then dispatch via SetIndexedSlot with handler
 * Ov168_AiDecelUntilAnimEnd. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov168_AiDecelUntilAnimEnd();

void Ov168_SetPose4ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 4, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov168_AiDecelUntilAnimEnd);
}
