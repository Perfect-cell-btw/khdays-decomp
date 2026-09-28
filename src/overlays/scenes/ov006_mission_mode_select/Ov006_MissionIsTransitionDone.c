#include "game/ov006_mission_mode_select.h"
/* Ov006_MissionIsTransitionDone -- Mission Mode: is the pending scene transition finished?
 * True when a transition is requested and no reliable message is still on its way. */
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

int Ov006_MissionIsTransitionDone(void) {
    if (MISSION_CONTEXT->transitionRequested != 0) {
        return MISSION_CONTEXT->sendBusy == 0;
    }
    return 0;
}
