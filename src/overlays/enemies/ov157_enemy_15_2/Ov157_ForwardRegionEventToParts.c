/* Inits the part objects from the event, then the base region handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(void *a, void *b);

void Ov157_ForwardRegionEventToParts(char *a, void *b) {
    int i;
    for (i = 0; i < 2; i++) {
        int *base = *(int **)(a + 0x3a4);
        Ov107_InitObjectFromSource((int)b, base[i]);
    }
    Ov107_HandleRegionEvent(a, b);
}
