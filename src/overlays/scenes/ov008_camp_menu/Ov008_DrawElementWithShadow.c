/* Draw a text/box element, optionally preceded by a drop-shadow pass offset by (+1,+1,-1). Both
 * passes use flags 0x821. */

#include "game/engine.h"

void Ov008_DrawElementWithShadow(int p1, int p2, int p3, int p4, int bShadow, int p6) {
    if (bShadow != 0) {
        Text_DrawDirectional_2(p1, p2 + 1, p3 + 1, p4 - 1, 0x821, p6);
    }
    Text_DrawDirectional_2(p1, p2, p3, p4, 0x821, p6);
}
