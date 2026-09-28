/* Ov006_MissionLeaveSubMenu_Ov105 -- Mission Mode: leave the current sub-menu, ov105 variant.
 * Same shape as Ov006_MissionLeaveSubMenu but hands off to Ov006_MissionSelectSceneCallback and finishes with the
 * ov105 teardown (Ov105_WH_Finalize) instead of the ov006 one. */
extern void Ov105_WH_SetReceiver(int a);
extern void Obj_SetField14(int obj, int next);
extern void Ov105_WH_Finalize(void);
extern void Ov006_MissionSelectSceneCallback(void);
extern int  data_ov006_020565e4;

void Ov006_MissionLeaveSubMenu_Ov105(void) {
    Ov105_WH_SetReceiver(0);
    Obj_SetField14(*(int *)((int)&data_ov006_020565e4 + 4), (int)Ov006_MissionSelectSceneCallback);
    Ov105_WH_Finalize();
}
