/* Inits the two head parts and the sixteen segment parts from the event, then the base region
 * handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int obj, int arg1);

void Ov283_ForwardRegionEventToParts(int *list, int target) {
    int i;
    for (i = 0; i < 2; i++)
        Ov107_InitObjectFromSource(target, list[i + 0xe7]);
    for (i = 0; i < 16; i++)
        Ov107_InitObjectFromSource(target, list[i + 0xe9]);
    Ov107_HandleRegionEvent((int)list, target);
}
