#include "game/ov008_camp_menu.h"
/* Update slot param_1's cached key/payload in the global table (MISSION_CONTEXT): if
 * param_2's key (*param_2) differs from the slot's (+0xc), store it, copy param_2's payload
 * (param_2+1) into the slot's buffer (table+param_1*8+8), and if the table's dirty flag
 * (+0x28) is set, mark slot param_1 dirty (table+param_1*4+0x30 = 1). */
extern void MI_CpuCopy8(void *src, void *dst, unsigned int n);
#define MISSION_CONTEXT ((int)data_ov008_02090f24.pContext)
void Ov008_UpdateSlotCache(int param_1, int *param_2, unsigned int param_3) {
    int key;
    if (param_2 == 0) {
        return;
    }
    key = *param_2;
    if (key != *(int *)(MISSION_CONTEXT + param_1 * 8 + 0xc)) {
        *(int *)(MISSION_CONTEXT + param_1 * 8 + 0xc) = key;
        MI_CpuCopy8(param_2 + 1, *(void **)(MISSION_CONTEXT + param_1 * 8 + 8), param_3);
        if (*(int *)(MISSION_CONTEXT + 0x28) != 0) {
            *(int *)(MISSION_CONTEXT + param_1 * 4 + 0x30) = 1;
        }
    }
}
