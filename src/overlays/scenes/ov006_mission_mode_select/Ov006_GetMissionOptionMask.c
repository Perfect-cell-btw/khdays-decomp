#include "game/ov006_mission_mode_select.h"
/* Read the u16 at +0x434 of the ov006 global object, or 0 if absent. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_GetMissionOptionMask(void) {
    if (MISSION_CONTEXT != 0) return MISSION_CONTEXT->message.selection.sessionMask;
    return 0;
}
