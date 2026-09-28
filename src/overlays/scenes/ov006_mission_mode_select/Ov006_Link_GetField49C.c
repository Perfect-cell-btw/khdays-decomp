#include "game/ov006_mission_mode_select.h"
/* Returns a word at a fixed offset of the object a global points to. */

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_Link_GetField49C(void) {
    return *(int *)((int)data_ov006_020565e4.pContext + 0x49c);
}
