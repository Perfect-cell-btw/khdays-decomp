/* Ov025_ClosePopup -- close the active menu popup, ov008.
 * On the active record: if it is modal-but-unconfirmed (rec+0x40 set, rec+0x44 clear) or has
 * no popup open (rec+0x4f8 == 0), does nothing. Otherwise dismisses the popup (Ov025_ApplyModeWidgets
 * when rec+0x4fc set), releases it (Ov025_ShowMissionListInfoPanel) and commits the input latch. */
extern int  Ov025_GetPageB(void);
extern void Ov025_ApplyModeWidgets(int rec, int a);
extern void Ov025_ShowMissionListInfoPanel(int rec, int a);
extern void PlaySound(int a, int b);

void Ov025_ClosePopup(void) {
    int rec = Ov025_GetPageB();
    if (*(int *)(rec + 0x40) != 0 && *(int *)(rec + 0x44) == 0) {
        return;
    }
    if (*(int *)(rec + 0x4f8) == 0) {
        return;
    }
    if (*(int *)(rec + 0x4fc) != 0) {
        Ov025_ApplyModeWidgets(rec, 0);
    }
    Ov025_ShowMissionListInfoPanel(rec, 0);
    PlaySound(0, 3);
}
