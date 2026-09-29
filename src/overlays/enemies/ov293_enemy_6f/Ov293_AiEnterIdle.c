/* Loops anim 1, resets the timer and installs the idle tick. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *a, int b, void *cb);
extern void Ov293_IdleTick(void);

void Ov293_AiEnterIdle(char *a) {
    char *p = *(char **)(a + 0x4);
    Ov107_PostTagUpdate((Actor *)(*(int *)p), 1, 1);
    *(int *)(p + 0x40) = 0;
    SetIndexedSlot(a, *(signed char *)(a + 0x20), Ov293_IdleTick);
}
