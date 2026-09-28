#include "game/ov008_camp_menu.h"
/* Returns a byte of the object a global points to. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_IsMissionMenuExitRequested(void)
{
    return *(unsigned char *)(MISSION_CONTEXT + 0x4ef);
}
