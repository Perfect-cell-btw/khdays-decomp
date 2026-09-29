extern char *NNSi_FndGetCurrentRootHeap(void);
extern int LoadGlobalU16At0(void);
extern void setDualArrayEntry(int engine, void *handler, int a);
extern void Pause_LoadResources(void);
extern int *Session_GetSetup(void);
extern void StoreGlobalPtrArray4At0c(int slot, void *handler);
extern void Game_EnterPauseScene(void);
extern void PauseMenu_Frame(void);
extern void Scene_Leave(void);
extern void GameConfig_Load(void);
extern void SetGlobalShort2To1(void);
extern void PauseMenu_PollInput(void);
extern char *data_0204be08;

/* Boots the 3D subsystem: clears the scene block's five counters, installs the three engine
 * handlers unless the language gates them, and arms the two debug hooks. */
void *Boot3DSubsystem(void) {
    char *self = NNSi_FndGetCurrentRootHeap();
    (&data_0204be08)[1] = self;
    *(int *)((&data_0204be08)[1] + 0xd8) = 0;
    *(int *)((&data_0204be08)[1] + 0xdc) = 0;
    *(int *)((&data_0204be08)[1] + 0xe4) = 0;
    *(int *)((&data_0204be08)[1] + 0xe8) = 0;
    *(int *)((&data_0204be08)[1] + 0xc8) = 0;
    *(int *)((&data_0204be08)[1] + 0xc4) = -1;
    if ((LoadGlobalU16At0() & 2) == 0 || (LoadGlobalU16At0() & 0x40) == 0) {
        setDualArrayEntry(0, (void *)&Game_EnterPauseScene, 0);
        setDualArrayEntry(1, (void *)&PauseMenu_Frame, 0);
        setDualArrayEntry(2, (void *)&Scene_Leave, 0);
    }
    Pause_LoadResources();
    if (*Session_GetSetup() != 1) {
        *(unsigned short *)&data_0204be08 = 0;
        StoreGlobalPtrArray4At0c(0x11, (void *)&GameConfig_Load);
        if ((LoadGlobalU16At0() & 2) == 0) {
            *(unsigned short *)((char *)&data_0204be08 + 2) = 0;
            StoreGlobalPtrArray4At0c(0x12, (void *)&SetGlobalShort2To1);
        }
    }
    return (void *)&PauseMenu_PollInput;
}
