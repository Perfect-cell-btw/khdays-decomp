/* Refreshes the child selection, then runs the object tick. */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(void *a, void *b);

void Ov293_TickWithChildRefresh(char *a, void *b) {
    Ov107_RefreshAndSelectChild(*(int *)(a + 0x39c), (int)b);
    Ov107_ProcessObjectTick(a, b);
}
