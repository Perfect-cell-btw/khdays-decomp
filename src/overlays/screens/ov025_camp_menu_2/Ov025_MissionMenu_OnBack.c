/* Ov025_MissionMenu_OnBack -- close the active mission-info popup, ov008.
 * If the record is modal-but-unconfirmed (rec+0x150 set, rec+0x154 clear) or has no popup open
 * (rec+0x180 == 0), does nothing. Otherwise dismisses (Ov025_ApplyModeWidgets2 when rec+0x184 set),
 * releases (Ov025_ShowMissionInfoPanel) and commits the input latch. */
extern int  Ov025_GetPageB(void);
extern void Ov025_ApplyModeWidgets2(int rec, int a);
extern void Ov025_ShowMissionInfoPanel(int rec, int a);
extern void PlaySound(int a, int b);

void Ov025_MissionMenu_OnBack(void) {
    int rec = Ov025_GetPageB();
    if (*(int *)(rec + 0x150) != 0 && *(int *)(rec + 0x154) == 0) {
        return;
    }
    if (*(int *)(rec + 0x180) == 0) {
        return;
    }
    if (*(int *)(rec + 0x184) != 0) {
        Ov025_ApplyModeWidgets2(rec, 0);
    }
    Ov025_ShowMissionInfoPanel(rec, 0);
    PlaySound(0, 3);
}
