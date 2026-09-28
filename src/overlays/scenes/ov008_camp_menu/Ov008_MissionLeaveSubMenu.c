extern int data_ov008_02090f24[];
extern void Ov105_WH_SetReceiver(int arg0);
extern void Obj_SetField14(int arg0, void (*callback)(void));
extern void Ov008_TickCardTransferScene(void);
extern void Ov008_GetIdleHandler(void);

void Ov008_MissionLeaveSubMenu(void)
{
    Ov105_WH_SetReceiver(0);
    Obj_SetField14(data_ov008_02090f24[1], Ov008_GetIdleHandler);
    Ov008_TickCardTransferScene();
}
