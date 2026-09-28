#include "game/ov006_mission_mode_select.h"
/* Ov006_SetPendingInput -- set the Mission Mode-screen "pending input" state.
 * When the input object is live (ctx+0x4e8 != 0), set its ready bit (ctx+0x4ad bit0) and store
 * the key/param at ctx+0x4ae. Always sets the top-level pending bit (ctx+0x4a8 bit0). */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

void Ov006_SetPendingInput(unsigned char param_1) {
    if (MISSION_CONTEXT->localMode != 0) {
        MISSION_CONTEXT->liveEntries.entries[0].flags.selectable = 1;
        MISSION_CONTEXT->liveEntries.entries[0].characterId = param_1;
    }
    MISSION_CONTEXT->liveEntries.header.bits.locked = 1;
}
