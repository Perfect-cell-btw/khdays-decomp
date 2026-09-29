/* Refreshes the child selector at +0x3d0 and runs the tick (disabled while flagged). */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov257_TickWithChildRefresh(char *self, void *b) {
    if (*(unsigned short *)(self + 0x1ac) & 2) {
        b = 0;
    }
    Ov107_RefreshAndSelectChild(*(int *)(self + 0x3d0), (int)b);
    Ov107_ProcessObjectTick(self, b);
}
