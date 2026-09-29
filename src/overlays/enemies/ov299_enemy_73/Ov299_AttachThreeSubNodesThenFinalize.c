/* Region event: initialises each of the three part objects (+0x398) from the event source, then
 * runs the base region-event handler. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent();

void Ov299_AttachThreeSubNodesThenFinalize(int arg0, int arg1) {
    int i;
    for (i = 0; i < 3; i++)
        Ov107_InitObjectFromSource(arg1, ((int *)arg0)[i + 225]);
    Ov107_HandleRegionEvent(arg0, arg1);
}
