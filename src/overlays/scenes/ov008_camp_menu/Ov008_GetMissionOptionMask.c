#include "game/ov008_camp_menu.h"
/* Read the u16 at +0x434 of the ov008 global object, or 0 if absent. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_GetMissionOptionMask(void)
{
    if (MISSION_CONTEXT != 0) {
        return MISSION_CONTEXT->message.selection.sessionMask;
    }
    return 0;
}
