/* Plays anim 1 and installs the idle tick. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov276_IdleTick(void);

void Ov276_AiEnterIdle(char *a) {
    char *p = *(char **)(a + 0x4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 1, 0);
    *(int *)(p + 0x4c) = 0;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov276_IdleTick);
}
