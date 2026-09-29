/* Bind param_2 to the two sub-objects at (param_1)+0x5cc[0..1] and the one at +0x5d4,
 * then run the ov107 attach for the pair. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int a, int b);
void Ov212_ForwardRegionEventToParts(int param_1, int param_2) {
    int i;
    for (i = 0; i < 2; i++) {
        Ov107_InitObjectFromSource(param_2, ((int *)param_1)[i + 0x173]);
    }
    Ov107_InitObjectFromSource(param_2, *(int *)(param_1 + 0x5d4));
    Ov107_HandleRegionEvent(param_1, param_2);
}
