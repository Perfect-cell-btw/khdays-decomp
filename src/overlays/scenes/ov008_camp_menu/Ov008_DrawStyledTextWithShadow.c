/* Draws styled text twice for a one-pixel drop shadow (the shadow one layer lower); the style
 * selects the glyph flags. */

#include "game/engine.h"

void Ov008_DrawStyledTextWithShadow(int param_1, int param_2, int param_3, int param_4, unsigned char param_5, int param_6) {
    unsigned int flags;
    switch (param_6) {
    case 2: flags = 0x821; break;
    case 1: flags = 0x411; break;
    default: flags = 0x209; break;
    }
    Text_DrawDirectional_2(param_1, param_3 + 1, param_4 + 1, param_5 - 1, flags, param_2);
    Text_DrawDirectional_2(param_1, param_3, param_4, param_5, flags, param_2);
}
