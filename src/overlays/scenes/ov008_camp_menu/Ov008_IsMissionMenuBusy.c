#include "game/ov008_camp_menu.h"
/* Report the +0x498 busy flag or, when idle, bit 1 of the +0x42c byte. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_IsMissionMenuBusy(void)
{
    if (*(int *)(MISSION_CONTEXT + 0x498) != 0) {
        return 1;
    }
    return ((unsigned int)*(unsigned char *)(MISSION_CONTEXT + 0x42c) << 30) >> 31;
}
