/* Shows the tagged entry's slots when the menu is enabled and page B is in the matching state. */

extern int Ov025_GetPageB();
extern int Ov025_GetBlock4a80();
extern int data_ov025_020b575c;
extern int Ov025_FindEntryById();
extern void Ov025_SetEntrySlotsVisible();

void Ov025_TriggerTag47IfState1(void) {
    int x = Ov025_GetPageB();
    int a = Ov025_GetBlock4a80();
    if (data_ov025_020b575c == 0) return;
    if (*(int *)(x + 0x44) != 1) return;
    Ov025_SetEntrySlotsVisible(a, Ov025_FindEntryById(a, 0x47), 1);
}
