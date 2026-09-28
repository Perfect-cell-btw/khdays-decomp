#include "game/ov008_camp_menu.h"
/* Resets the wireless receiver, installs the mission-select scene callback and restarts it. */

extern void Ov105_WH_SetReceiver(int arg0);
extern void Obj_SetField14(int arg0, void (*callback)(void));
extern void Ov105_WH_Finalize(void);
extern void Ov008_MissionSelectSceneCallback(void);

void Ov008_Link_InstallSceneCallback(void)
{
    Ov105_WH_SetReceiver(0);
    Obj_SetField14((int)data_ov008_02090f24.pController, Ov008_MissionSelectSceneCallback);
    Ov105_WH_Finalize();
}
