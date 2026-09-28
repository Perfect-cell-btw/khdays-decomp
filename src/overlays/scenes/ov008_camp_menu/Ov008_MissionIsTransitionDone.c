#include "game/ov008_camp_menu.h"
/* Whether the mission transition has started and finished. */

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

int Ov008_MissionIsTransitionDone(void)
{
    if (MISSION_CONTEXT->transitionRequested != 0) {
        return MISSION_CONTEXT->sendBusy == 0;
    }

    return 0;
}
