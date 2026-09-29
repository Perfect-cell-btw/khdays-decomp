/* Ov025_DrawStringOptShadow -- draw a string, optionally with a 1px drop shadow (param_5) one colour
 * darker. Flags are fixed at 0x411. */

#include "game/engine.h"

void Ov025_DrawStringOptShadow(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    if (param_5 != 0) {
        Text_DrawDirectional_2(param_1, param_2 + 1, param_3 + 1, param_4 - 1, 0x411, param_6);
    }
    Text_DrawDirectional_2(param_1, param_2, param_3, param_4, 0x411, param_6);
}
