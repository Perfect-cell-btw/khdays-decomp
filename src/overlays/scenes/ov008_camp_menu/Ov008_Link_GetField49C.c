#include "game/ov008_camp_menu.h"
/* Returns the link context's word at +0x49c. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
int Ov008_Link_GetField49C(void)
{
    return MISSION_CONTEXT->busy;
}
