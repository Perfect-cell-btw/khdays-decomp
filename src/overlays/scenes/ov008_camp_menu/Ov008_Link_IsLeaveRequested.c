#include "game/ov008_camp_menu.h"
/* Whether leaving the link was requested. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_Link_IsLeaveRequested(void)
{
    return *(int *)(MISSION_CONTEXT + 0x4f4);
}
