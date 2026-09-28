#include "game/ov008_camp_menu.h"
/* Copy 0x58 bytes from (global + 0x436) into the caller's buffer. */
extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
#define MISSION_CONTEXT ((int)data_ov008_02090f24.pContext)

void Ov008_CopyMissionOptionTextRows(void *param_1) {
    int g = (int)data_ov008_02090f24.pContext;
    MI_CpuCopy8((const void *)(g + 0x436), param_1, 0x58);
}
