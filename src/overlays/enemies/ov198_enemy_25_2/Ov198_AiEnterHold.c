/* Plays anim 1, arms the 0x2000 hold timer and installs its tick. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov198_TickHoldTimer(void);

void Ov198_AiEnterHold(char *obj) {
    char *p = *(char **)(obj + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 1, 0);
    *(int *)(p + 0x40) = 0x2000;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov198_TickHoldTimer);
}
