#include "game/ov006_mission_mode_select.h"
/* Busy while the selection-message refresh timer runs; otherwise whether the selection
 * changed since it was last sent. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_IsMissionMenuBusy(void) {
    if (MISSION_CONTEXT->refreshTimer != 0) return 1;
    return MISSION_CONTEXT->message.selection.flags.bits.changed;
}
