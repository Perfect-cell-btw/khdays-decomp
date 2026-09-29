/* Ov008_DrawStringShadowed -- draw a string with a 1px drop shadow: renders it once offset by (+1,+1)
 * in shadow colour 1, then again at (x,y) in the requested colour. Both passes force flag bit 0. */

#include "game/engine.h"

void Ov008_DrawStringShadowed(int param_1, int param_2, int param_3, int param_4, int param_5, unsigned int param_6) {
    Text_DrawDirectional_2(param_1, param_3 + 1, param_4 + 1, 1, param_6 | 1, param_2);
    Text_DrawDirectional_2(param_1, param_3, param_4, param_5, param_6 | 1, param_2);
}
