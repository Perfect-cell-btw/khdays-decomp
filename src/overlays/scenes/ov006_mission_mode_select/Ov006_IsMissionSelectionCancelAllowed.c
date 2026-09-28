#include "game/ov006_mission_mode_select.h"
/* Whether the live entry block is locked (bit 0 of its header). */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_IsMissionSelectionCancelAllowed(void) {
    return MISSION_CONTEXT->liveEntries.header.bits.locked;
}
