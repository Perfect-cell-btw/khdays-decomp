#include "game/ov006_mission_mode_select.h"
/* Ov006_Link_Poll -- fetch field [10] of the ov006 context list node, ov006
 * (tail-call to Obj_GetWord28 over the node at *(&data_ov006_020565e4 + 4)). */
extern int Obj_GetWord28(int *node);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
int Ov006_Link_Poll(void) {
    return Obj_GetWord28((int *)data_ov006_020565e4.pController);
}
