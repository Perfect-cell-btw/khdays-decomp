/* Bind param_2 to the sub-object at (param_1)+0x3b8, then run the ov107 attach for the pair. */

#include "game/enemy_common.h"

extern void Ov107_ProcessObjectTick(int a, int b);
void Ov210_TickWithChildRefresh(int param_1, int param_2) {
    Ov107_RefreshAndSelectChild(*(int *)(param_1 + 0x3b8), param_2);
    Ov107_ProcessObjectTick(param_1, param_2);
}
