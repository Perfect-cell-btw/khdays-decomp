#include "game/ov008_camp_menu.h"
/* Whether the link runs in the local (single-player) mode; 1 without link state. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_Link_IsLocal(void)
{
    if (MISSION_CONTEXT != 0) {
        return MISSION_CONTEXT->localMode;
    }
    return 1;
}
