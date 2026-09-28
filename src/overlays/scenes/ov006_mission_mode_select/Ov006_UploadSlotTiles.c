#include "game/ov006_mission_mode_select.h"
/* Ov006_UploadSlotTiles -- upload slot param_1's tile data, then clear its pending pointer.
 * If param_2 is non-null, copy param_3 bytes from the slot's source (ctx[param_1].src at
 * ctx+param_1*8+8) into param_2; then zero the per-slot word at ctx+param_1*4+0x30. */
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

void Ov006_UploadSlotTiles(int param_1, unsigned short *param_2, unsigned int param_3) {
    if (param_2 != 0) {
        MI_CpuCopy8(MISSION_CONTEXT->workBuffers[param_1].buffer, param_2, param_3);
    }
    MISSION_CONTEXT->workStates[param_1] = 0;
}
