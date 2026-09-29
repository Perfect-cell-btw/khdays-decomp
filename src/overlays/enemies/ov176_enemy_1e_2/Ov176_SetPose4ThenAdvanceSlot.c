/* Push animation params (4, 0) to the sprite, then dispatch via SetIndexedSlot with handler
 * Ov176_AiDecelUntilAnimEnd. */

#include "game/enemy_common.h"

extern void SetIndexedSlot();
extern void Ov176_AiDecelUntilAnimEnd();

void Ov176_SetPose4ThenAdvanceSlot(int this_) {
    Ov107_PostTagUpdate((Actor *)(*(int *)(*(int *)(this_ + 4))), 4, 0);
    SetIndexedSlot(this_, *(signed char *)(this_ + 0x20), (int)&Ov176_AiDecelUntilAnimEnd);
}
