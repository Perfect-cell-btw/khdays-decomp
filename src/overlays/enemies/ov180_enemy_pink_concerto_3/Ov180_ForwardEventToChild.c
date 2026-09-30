/* Passes the event to the child object (+0x3ac), then to the base region-event handler. */

#include "game/enemy_common.h"

extern int Ov107_HandleRegionEvent();

int Ov180_ForwardEventToChild(int *r0, int r1) {
    Ov107_InitObjectFromSource(r1, r0[0x3ac / 4]);
    return Ov107_HandleRegionEvent(r0, r1);
}
