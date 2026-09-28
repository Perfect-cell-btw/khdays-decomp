/* Ov008_MissionConfirmGuard -- confirm-guard for the ov008 mission menu.
 * Gets the menu object (Ov008_GetPageB); bails if it is mid-slide (obj+0x150 set while
 * obj+0x154 clear) or has no pending selection (obj+0x180 clear). If the selection is not yet
 * armed (obj+0x184 clear), arm it (Ov008_ApplyModeWidgets2(.,1)); then run the confirm
 * (Ov008_StartSelectedMission). */
extern int  Ov008_GetPageB(void);
extern void Ov008_ApplyModeWidgets2(int obj, int arg);
extern void Ov008_StartSelectedMission(void);

void Ov008_MissionConfirmGuard(void) {
    int obj = Ov008_GetPageB();
    if (*(int *)(obj + 0x150) != 0 && *(int *)(obj + 0x154) == 0) {
        return;
    }
    if (*(int *)(obj + 0x180) == 0) {
        return;
    }
    if (*(int *)(obj + 0x184) == 0) {
        Ov008_ApplyModeWidgets2(obj, 1);
    }
    Ov008_StartSelectedMission();
}
