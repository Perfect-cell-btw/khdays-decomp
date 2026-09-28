#include "game/ov008_camp_menu.h"
/* Returns the link context's word at +0x49c. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_Link_GetField49C(void)
{
    return *(int *)(MISSION_CONTEXT + 0x49c);
}
