#include "game/ov008_camp_menu.h"
/* Whether the link runs in the local (single-player) mode; 1 without link state. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)
int Ov008_Link_IsLocal(void)
{
    if (MISSION_CONTEXT != 0) {
        return *(int *)(MISSION_CONTEXT + 0x4e8);
    }
    return 1;
}
