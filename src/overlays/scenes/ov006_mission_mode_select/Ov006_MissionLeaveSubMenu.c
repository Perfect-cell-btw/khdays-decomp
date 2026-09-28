/* Ov006_MissionLeaveSubMenu -- Mission Mode: leave the current sub-menu back to the previous screen.
 * Silences the ov105 sound channel, hands the scene object (data_ov006_020565e4[1]) over to
 * Obj_SetField14 with Ov006_GetIdleHandler as its next state, then runs the shared teardown. */
extern void Ov105_WH_SetReceiver(int a);
extern void Obj_SetField14(int obj, int next);
extern void Ov006_TickCardTransferScene(void);
extern void Ov006_GetIdleHandler(void);
extern int  data_ov006_020565e4;

void Ov006_MissionLeaveSubMenu(void) {
    Ov105_WH_SetReceiver(0);
    Obj_SetField14(*(int *)((int)&data_ov006_020565e4 + 4), (int)Ov006_GetIdleHandler);
    Ov006_TickCardTransferScene();
}
