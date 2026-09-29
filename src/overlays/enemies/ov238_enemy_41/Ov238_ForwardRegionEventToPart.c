/* Inits the part object (+0x384) from the event, then the base region handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov238_ForwardRegionEventToPart(char *a, void *b) {
    Ov107_InitObjectFromSource((int)b, *(int *)(a + 0x384));
    Ov107_HandleRegionEvent(a, b);
}
