/* Ov008_Page2ConfirmGuard -- confirm-guard for a second ov008 menu page (same shape as 02078214).
 * Bails if mid-slide (obj+0x40 set while obj+0x44 clear) or nothing pending (obj+0x4f8 clear);
 * arms the selection if not armed (obj+0x4fc clear) then runs the confirm (Ov008_MissionListSelect). */
extern int  Ov008_GetPageB(void);
extern void Ov008_ApplyModeWidgets(int obj, int arg);
extern void Ov008_MissionListSelect(int obj);

void Ov008_Page2ConfirmGuard(void) {
    int obj = Ov008_GetPageB();
    if (*(int *)(obj + 0x40) != 0 && *(int *)(obj + 0x44) == 0) {
        return;
    }
    if (*(int *)(obj + 0x4f8) == 0) {
        return;
    }
    if (*(int *)(obj + 0x4fc) == 0) {
        Ov008_ApplyModeWidgets(obj, 1);
    }
    Ov008_MissionListSelect(obj);
}
