extern void Ov025_ShowMissionInfoPanel();
extern void PlaySound();
extern void Ov025_SetGlobalConfigAndInit();

void Ov025_TeardownOrInit(int arg0) {
    if (*(int *)(arg0 + 0x180) != 0) {
        *(int *)(arg0 + 0x184) = 0;
        Ov025_ShowMissionInfoPanel(arg0, 0);
        PlaySound(0, 3);
        return;
    }
    Ov025_SetGlobalConfigAndInit(1);
    PlaySound(0, 3);
}
