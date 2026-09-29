/* Passes the event to the child object (+0x3c8), then to the base region-event handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov143_ForwardEventToChild(char *a, void *b) {
    Ov107_InitObjectFromSource((int)b, *(int *)(a + 0x3c8));
    Ov107_HandleRegionEvent(a, b);
}
