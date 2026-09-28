#include "game/ov008_camp_menu.h"
/* Returns a byte of the object a global points to. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_IsMissionMenuExitRequested(void)
{
    return MISSION_CONTEXT->signal;
}
