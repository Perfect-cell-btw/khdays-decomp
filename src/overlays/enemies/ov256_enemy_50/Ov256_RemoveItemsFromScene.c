/* Scene hook of the ov256 enemy: removes its two +0x434 items and the five +0x43c items from the
 * scene (arg 1) and chains to the common handler. */

#include "game/enemy_common.h"

extern void Ov107_Actor_DetachFromRegion(int obj, int arg1);

void Ov256_RemoveItemsFromScene(int *list, int target) {
    int i;
    for (i = 0; i < 2; i++)
        Ov107_InvokeSlot0x74(target, list[i + 0x10d]);
    for (i = 0; i < 0x5; i++)
        Ov107_InvokeSlot0x74(target, list[i + 0x10f]);
    Ov107_Actor_DetachFromRegion((int)list, target);
}
