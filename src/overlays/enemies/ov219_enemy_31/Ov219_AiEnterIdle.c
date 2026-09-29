/* Plays looping anim 0, arms the 0x1000 timer and installs the countdown. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov219_AiIdleCountdown(void);

void Ov219_AiEnterIdle(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 0, 1);
    *(int *)(p + 0x14) = 0x1000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov219_AiIdleCountdown);
}
