/* Ov259_ForwardRegionEventToParts -- hand both sub-objects (+0x384, +0x388) to the visitor and then run the
 * base pass. The visitor takes (arg, object), not the other way round. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int obj, int arg);

void Ov259_ForwardRegionEventToParts(int obj, int arg) {
    Ov107_InitObjectFromSource(arg, *(int *)(obj + 0x384));
    Ov107_InitObjectFromSource(arg, *(int *)(obj + 0x388));
    Ov107_HandleRegionEvent(obj, arg);
}
