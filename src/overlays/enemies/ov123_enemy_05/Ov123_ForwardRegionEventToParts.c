/* Inits the part objects from the event, then the base region handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov123_ForwardRegionEventToParts(char *a, void *b) {
    Ov107_InitObjectFromSource((int)b, *(int *)(a + 0x394));
    Ov107_HandleRegionEvent(a, b);
}
