#include "game/ov008_camp_menu.h"
/* Whether leaving the link was requested. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_Link_IsLeaveRequested(void)
{
    return MISSION_CONTEXT->transferA;
}
