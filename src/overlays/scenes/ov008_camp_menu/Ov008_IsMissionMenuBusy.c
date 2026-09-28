#include "game/ov008_camp_menu.h"
/* Report the +0x498 busy flag or, when idle, bit 1 of the +0x42c byte. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_IsMissionMenuBusy(void)
{
    if (MISSION_CONTEXT->refreshTimer != 0) {
        return 1;
    }
    return MISSION_CONTEXT->message.selection.flags.bits.changed;
}
