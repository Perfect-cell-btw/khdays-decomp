/* Passes the event to each child of the 8-entry array at +0x3c0, then to the base region-event
 * handler. */

#include "game/enemy_common.h"

extern int Ov107_HandleRegionEvent();

int Ov233_ForwardEventToChildren(int *r0, int r1) {
    int i;
    for (i = 0; i < 8; i++) {
        Ov107_InitObjectFromSource(r1, r0[0xf0 + i]);
    }
    return Ov107_HandleRegionEvent(r0, r1);
}
