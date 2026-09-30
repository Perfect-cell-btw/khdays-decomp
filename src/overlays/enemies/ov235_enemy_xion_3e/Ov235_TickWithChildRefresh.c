/* Refreshes the child selector at +0x3a8 and runs the tick (disabled while flagged). */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *a, int flag);

void Ov235_TickWithChildRefresh(char *a, int b) {
    if (*(unsigned short *)(a + 0x1ac) & 2) {
        b = 0;
    }
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x3a8), b);
    Ov107_ProcessObjectTick(a, b);
}
