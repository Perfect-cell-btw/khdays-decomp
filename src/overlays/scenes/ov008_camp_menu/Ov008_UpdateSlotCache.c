#include "game/ov008_camp_menu.h"
/* Update work buffer param_1 of the mission context: if param_2's key (*param_2) differs from the
 * buffer's, store it, copy param_2's payload (param_2 + 1) into the buffer, and while a
 * transition is requested mark the buffer's state (workStates) as 1. */
extern void MI_CpuCopy8(void *src, void *dst, unsigned int n);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
void Ov008_UpdateSlotCache(int param_1, int *param_2, unsigned int param_3) {
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
