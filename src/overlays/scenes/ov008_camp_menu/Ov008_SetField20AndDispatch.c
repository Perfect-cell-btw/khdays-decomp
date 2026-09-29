/* Selects a save page and rebuilds the action page for the current mode, with a sound. */

#include "game/engine.h"

extern void Ov008_BuildActionPage(void *context, int arg1);

void Ov008_SetField20AndDispatch(void *context, int value)
{
    *(int *)((char *)context + 0x20) = value;

    if (*(int *)((char *)context + 0xa4) == 1) {
        Ov008_BuildActionPage(context, 2);
    } else {
        Ov008_BuildActionPage(context, 5);
    }

    PlaySound(0, 1);
}
