/* Refreshes the child selector at +0x430, then runs the object tick. */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov254_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x430), (int)b);
    Ov107_ProcessObjectTick(a, b);
}
