#include "game/ov008_camp_menu.h"
/* Leaves the mission sub-menu: clears the wireless receiver and installs the idle handler. */

extern void Ov105_WH_SetReceiver(int arg0);
extern void Obj_SetField14(int arg0, void (*callback)(void));
extern void Ov008_TickCardTransferScene(void);
extern void Ov008_GetIdleHandler(void);

void Ov008_MissionLeaveSubMenu(void)
{
    Ov105_WH_SetReceiver(0);
    Obj_SetField14((int)data_ov008_02090f24.pController, Ov008_GetIdleHandler);
    Ov008_TickCardTransferScene();
}
