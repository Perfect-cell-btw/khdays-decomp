/* Scene hook of the ov258 enemy: adds its two +0x458 items to the scene (arg 1) and
 * chains to the common handler. */

#include "game/enemy_common.h"

extern int Ov107_HandleRegionEvent(int *self, int scene);

int Ov258_AddItemsToScene(int *r0, int r1)
{
    signed char i;

    for (i = 0; i < 2; i++) {
        Ov107_InitObjectFromSource(r1, r0[i + 0x116]);
    }
    return Ov107_HandleRegionEvent(r0, r1);
}
