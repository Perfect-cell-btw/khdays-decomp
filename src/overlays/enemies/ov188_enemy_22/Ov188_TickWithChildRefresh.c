/* Refreshes the child selector at +0x3c0, then runs the object tick. */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov188_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x3c0), (int)b);
    Ov107_ProcessObjectTick(a, b);
}
