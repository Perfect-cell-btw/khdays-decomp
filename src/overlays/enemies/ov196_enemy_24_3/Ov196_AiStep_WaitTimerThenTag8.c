/* AI step: accumulates the owner's frame delta into context +0x30; at 0x3000 posts tag 8 and
 * installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov196_AiStep_QueueAction2OnAnimEnd(void);

void Ov196_AiStep_WaitTimerThenTag8(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x30) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x30) = val;
    if (val < 0x3000) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 8, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov196_AiStep_QueueAction2OnAnimEnd);
}
