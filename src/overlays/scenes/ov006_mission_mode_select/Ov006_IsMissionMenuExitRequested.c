#include "game/ov006_mission_mode_select.h"
/* Returns a byte of the object a global points to. */

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_IsMissionMenuExitRequested(void) {
    return *(unsigned char *)((int)data_ov006_020565e4.pContext + 0x4ef);
}
