/* Feed the two sub-values at param_1+0x38c/+0x390 to Ov107_InitObjectFromSource with param_2, then
 * finalize via Ov107_HandleRegionEvent. */

#include "game/enemy_common.h"

extern void Ov107_HandleRegionEvent(int a, int b);
void Ov265_ForwardEventToChildren(int param_1, int param_2) {
    int i;
    for (i = 0; i < 2; i++) {
        Ov107_InitObjectFromSource(param_2, ((int *)param_1)[i + 0xe3]);
    }
    Ov107_HandleRegionEvent(param_1, param_2);
}
