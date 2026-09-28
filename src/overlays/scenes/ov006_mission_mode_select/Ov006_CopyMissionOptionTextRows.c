#include "game/ov006_mission_mode_select.h"
/* Copy 0x58 bytes from (global + 0x436) into the caller's buffer. */
extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

void Ov006_CopyMissionOptionTextRows(void *param_1) {
    int g = (int)data_ov006_020565e4.pContext;
    MI_CpuCopy8((const void *)(g + 0x436), param_1, 0x58);
}
