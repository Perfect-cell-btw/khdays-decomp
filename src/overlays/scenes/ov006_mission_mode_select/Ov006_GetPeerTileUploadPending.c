#include "game/ov006_mission_mode_select.h"
/* Read the +0x30 word of element param of the ov006 global array. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_GetPeerTileUploadPending(int param_1) {
    return MISSION_CONTEXT->workStates[param_1];
}
