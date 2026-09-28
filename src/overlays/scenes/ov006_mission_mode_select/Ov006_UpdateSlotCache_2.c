#include "game/ov006_mission_mode_select.h"
/* Update slot param_1's cached key/payload in the global table (MISSION_CONTEXT): if
 * param_2's key (*param_2) differs from the slot's (+0xc), store it, copy param_2's payload
 * (param_2+1) into the slot's buffer (table+param_1*8+8), and if the table's dirty flag
 * (+0x28) is set, mark slot param_1 dirty (table+param_1*4+0x30 = 1). */
extern void MI_CpuCopy8(void *src, void *dst, unsigned int n);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
void Ov006_UpdateSlotCache_2(int param_1, int *param_2, unsigned int param_3) {
    int key;
    if (param_2 == 0) {
        return;
    }
    key = *param_2;
    if (key != MISSION_CONTEXT->workBuffers[param_1].key) {
        MISSION_CONTEXT->workBuffers[param_1].key = key;
        MI_CpuCopy8(param_2 + 1, MISSION_CONTEXT->workBuffers[param_1].buffer, param_3);
        if (MISSION_CONTEXT->transitionRequested != 0) {
            MISSION_CONTEXT->workStates[param_1] = 1;
        }
    }
}
