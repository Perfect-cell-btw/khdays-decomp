/* Shows the entry tagged 0x48 on page B when the page is idle. */

extern int Ov008_GetPageB();
extern int Ov008_GetCtxBlock4a80();
extern int data_ov008_02090f20;
extern int Ov008_FindEntryById();
extern void Ov008_SetEntrySlotsVisible();

void Ov008_TriggerTag48IfState0(void) {
    int x = Ov008_GetPageB();
    int a = Ov008_GetCtxBlock4a80();
    if (data_ov008_02090f20 == 0) return;
    if (*(int *)(x + 0x44) != 0) return;
    Ov008_SetEntrySlotsVisible(a, Ov008_FindEntryById(a, 0x48), 1);
}
