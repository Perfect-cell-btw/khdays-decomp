/* Sets bit 1 on the object's two slots that are in use. */

#include "game/engine.h"

void Ov025_ReleaseTwoSlots_2(int arg0, int arg1) {
    int i = 0;
    do {
        int v = ((int *)arg1)[i + 5];
        if (v != -1) Slot_SetFlagBit1(arg0, v);
        i++;
    } while (i < 2);
}
