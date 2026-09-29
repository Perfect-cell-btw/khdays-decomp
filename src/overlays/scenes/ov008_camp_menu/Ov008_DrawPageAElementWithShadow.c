/* Draw a page-A element via Text_DrawDirectional_2, optionally preceded by a drop-shadow pass offset by
 * (+1,+1,-1). The element base is page A + 0x10; param_1 is forwarded as the draw's last argument. */

#include "game/engine.h"

extern int Ov008_GetMenuContext(void);

void Ov008_DrawPageAElementWithShadow(int param_1, int param_2, int param_3, int param_4, unsigned int param_5, int param_6) {
    int page = Ov008_GetMenuContext();
    if (param_6 != 0) {
        Text_DrawDirectional_2(page + 0x10, param_2 + 1, param_3 + 1, param_4 - 1, param_5, param_1);
    }
    Text_DrawDirectional_2(page + 0x10, param_2, param_3, param_4, param_5, param_1);
}
