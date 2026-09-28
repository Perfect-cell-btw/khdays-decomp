#include "game/ov006_mission_mode_select.h"
/* Ov006_SetTickSlotByte -- store param_1 at ctx+0x42a, and (only when the tick source is up)
 * mirror it into the per-tick slot at ctx + tick + 0x48e. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
extern int func_01ff8128(void);

void Ov006_SetTickSlotByte(unsigned char param_1) {
    MISSION_CONTEXT->selectionBlock[0x16] = param_1;
    if (func_01ff8128() != 0) {
        return;
    }
    MISSION_CONTEXT->message.selection.peerStatus[func_01ff8128()] = param_1;
}
