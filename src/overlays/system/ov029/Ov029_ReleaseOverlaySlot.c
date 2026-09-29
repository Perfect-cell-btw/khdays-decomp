/* Unloads an overlay and frees its slot in the overlay table. */

#include "game/engine.h"

extern int data_ov029_020b3200[];
void Ov029_ReleaseOverlaySlot(int param_1)
{
    int i;
    int *p;
    UnloadOverlaySync(0, param_1);
    p = data_ov029_020b3200;
    for (i = 0; i < 4; i++) {
        if (param_1 == *p) {
            data_ov029_020b3200[i] = -1;
            return;
        }
        p++;
    }
}
