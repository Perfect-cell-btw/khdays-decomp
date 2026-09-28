#include "game/ov006_mission_mode_select.h"
/* Read the byte at +0x4f0 of the ov006 global object. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_Link_GetField4F0(void) {
    return MISSION_CONTEXT->startFailed;
}
