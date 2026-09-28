/* Main state of the ov106 scene. On the sub screen (+0x8e48 = 1), once the caption script finishes
 * (02020e58) it is closed and, for end kinds 0-2 (+0x12c; kind 1 also starts +0x130), the layers are
 * reset and the state moves on to 020b7728. Otherwise the layers are refreshed, the main screen runs
 * its camera step, the frame is committed (02023c30) and a set field 0x20e6 starts the exit (020b8130);
 * the state stays. */
extern char *data_ov106_020b8b60;
extern int Game_RunActionScript(void *script);
extern void Obj_ResetBothSubBlocksAndArm(void *script);
extern void Ov002_World_SetPendingEntryOnce(int a);
extern void Ov106_SelectScreenLayers(void);
extern void Ov106_CameraStep(void);
extern void SetGameMode(int a);
extern unsigned int GameState_GetField(int nField, int nBits);
extern void Ov106_ArmObject(void);
extern int Ov106_ApplySlotFlags(void);

void *Ov106_MainState(void)
{
    if (*(int *)(data_ov106_020b8b60 + 0x8e48) == 1 && Game_RunActionScript(data_ov106_020b8b60) == 0) {
        Obj_ResetBothSubBlocksAndArm(data_ov106_020b8b60);
        switch (*(int *)(data_ov106_020b8b60 + 0x12c)) {
        case 1:
            Ov002_World_SetPendingEntryOnce(*(int *)(data_ov106_020b8b60 + 0x130));
        case 0:
        case 2:
            Ov106_SelectScreenLayers();
            return Ov106_ApplySlotFlags;
        }
    }
    Ov106_SelectScreenLayers();
    if (*(int *)(data_ov106_020b8b60 + 0x8e48) == 0) {
        Ov106_CameraStep();
    }
    SetGameMode(2);
    if (GameState_GetField(0x20e6, 1) == 1) {
        Ov106_ArmObject();
    }
    return 0;
}
