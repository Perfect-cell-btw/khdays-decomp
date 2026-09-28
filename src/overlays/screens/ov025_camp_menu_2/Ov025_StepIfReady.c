extern int Ov025_GetPageB();
extern void Ov025_ApplyModeWidgets2();
extern void Ov025_MissionList_StartMission();

void Ov025_StepIfReady(void) {
    int x = Ov025_GetPageB();
    if (*(int *)(x + 0x150) != 0 && *(int *)(x + 0x154) == 0) return;
    if (*(int *)(x + 0x180) == 0) return;
    if (*(int *)(x + 0x184) == 0) Ov025_ApplyModeWidgets2(x, 1);
    Ov025_MissionList_StartMission();
}
