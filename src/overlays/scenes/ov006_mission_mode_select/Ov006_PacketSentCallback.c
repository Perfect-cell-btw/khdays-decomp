#include "game/ov006_mission_mode_select.h"
/* Send completion callback: clears the mission sync context's busy flag (+0x2c). */

/* Clear +0x2c of the ov006 global object. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
void Ov006_PacketSentCallback(void) {
    MISSION_CONTEXT->sendBusy = 0;
}
