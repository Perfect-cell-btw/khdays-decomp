/* Ov008_EnableMissionRowOnPage1 -- when the menu is on page state 1, enable the mission list's tag-0x47 row.
 * Gets the menu object (Ov008_GetPageB) and its list (Ov008_GetCtxBlock4a80); bails unless the
 * global gate data_02090f20 is set and obj+0x44 == 1; then enables the row (Ov008_SetEntrySlotsVisible). */
extern int  Ov008_GetPageB(void);
extern int  Ov008_GetCtxBlock4a80(void);
extern int  Ov008_FindEntryById(int list, int tag);
extern void Ov008_SetEntrySlotsVisible(int list, int row, int enabled);
extern int  data_ov008_02090f20;

void Ov008_EnableMissionRowOnPage1(void) {
    int obj = Ov008_GetPageB();
    int list = Ov008_GetCtxBlock4a80();
    if (data_ov008_02090f20 == 0) {
        return;
    }
    if (*(int *)(obj + 0x44) != 1) {
        return;
    }
    {
        int row = Ov008_FindEntryById(list, 0x47);
        Ov008_SetEntrySlotsVisible(list, row, 1);
    }
}
