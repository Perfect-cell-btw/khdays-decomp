#include "game/ov006_mission_mode_select.h"
/* Ov006_MissionLeaveSubMenu -- Mission Mode: leave the current sub-menu back to the previous screen.
 * Clears the ov105 receiver, gives the controller instance Ov006_GetIdleHandler as its next
 * state (Obj_SetField14), then runs the shared teardown. */
extern void Ov105_WH_SetReceiver(int a);
extern void Obj_SetField14(int obj, int next);
extern void Ov006_TickCardTransferScene(void);
extern void Ov006_GetIdleHandler(void);

void Ov006_MissionLeaveSubMenu(void) {
    Ov105_WH_SetReceiver(0);
    Obj_SetField14((int)data_ov006_020565e4.pController, (int)Ov006_GetIdleHandler);
    Ov006_TickCardTransferScene();
}
