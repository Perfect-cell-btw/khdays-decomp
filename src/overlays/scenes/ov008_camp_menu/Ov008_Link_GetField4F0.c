#include "game/ov008_camp_menu.h"
/* Read the byte at +0x4f0 of the ov008 global object. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_Link_GetField4F0(void)
{
    return *(unsigned char *)(MISSION_CONTEXT + 0x4f0);
}
