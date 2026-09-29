/* After 0x4000 plays anim 11 and installs the next step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov204_AiStep_QueueAction2OnFlag28Clear_3(void);

void Ov204_AiWaitThenAnim11(char *obj) {
    char *p = *(char **)(obj + 4);
    int val = *(int *)(p + 0x2c) + *(int *)(*(char **)obj + 0x2c);
    *(int *)(p + 0x2c) = val;
    if (val < 0x4000) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 11, 0);
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov204_AiStep_QueueAction2OnFlag28Clear_3);
}
