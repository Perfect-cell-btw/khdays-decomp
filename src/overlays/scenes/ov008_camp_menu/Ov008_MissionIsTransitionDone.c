#include "game/ov008_camp_menu.h"
/* Whether the mission transition has started and finished. */

#define MISSION_CONTEXT ((char *)data_ov008_02090f24.pContext)

int Ov008_MissionIsTransitionDone(void)
{
    if (*(int *)(MISSION_CONTEXT + 0x28) != 0) {
        return *(int *)(MISSION_CONTEXT + 0x2c) == 0;
    }

    return 0;
}
