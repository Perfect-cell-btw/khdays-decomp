/* Unlinks the two arrow cells. */

#include "game/engine.h"

extern char *data_ov026_02091368[];

void Ov026_Shop_HideArrows(void)
{
    char *base = data_ov026_02091368[0];
    int *values = (int *)(base + 0xc54c);
    void *object = *(void **)(base + 0xbfb0);

    Slot_UnlinkIfLinked(object, values[0]);
    Slot_UnlinkIfLinked(object, values[1]);
}
