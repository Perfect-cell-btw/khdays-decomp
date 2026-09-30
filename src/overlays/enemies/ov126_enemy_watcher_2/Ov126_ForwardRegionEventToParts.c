/* Bind param_2 to the two sub-objects at (param_1)+0x3a0[0..1], then run the ov107 attach. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int a, int b);
void Ov126_ForwardRegionEventToParts(int param_1, int param_2) {
    int i;
    for (i = 0; i < 2; i++) {
        Ov107_InitObjectFromSource(param_2, ((int *)param_1)[i + 0xe8]);
    }
    Ov107_HandleRegionEvent(param_1, param_2);
}
