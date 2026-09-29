/* Scene hook of the ov258 enemy: removes its two +0x458 items from the scene (arg 1) and
 * chains to the common handler. */

#include "game/enemy_common.h"

extern int Ov107_Actor_DetachFromRegion(int *self, int scene);

int Ov258_RemoveItemsFromScene(int *r0, int r1)
{
    signed char i;

    for (i = 0; i < 2; i++) {
        Ov107_InvokeSlot0x74(r1, r0[i + 0x116]);
    }
    return Ov107_Actor_DetachFromRegion(r0, r1);
}
