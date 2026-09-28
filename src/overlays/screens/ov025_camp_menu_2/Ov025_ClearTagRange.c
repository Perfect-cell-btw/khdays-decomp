/* Hides the entries 0xc9-0xdc of the layout. */

extern int data_ov025_020b575c;
extern int Ov025_GetBlock4a80();
extern int Ov025_FindEntryById();
extern void Ov025_SetEntrySlotsVisible();

void Ov025_ClearTagRange(void) {
    if (data_ov025_020b575c == 0) return;
    int a = Ov025_GetBlock4a80();
    int i = 0xc9;
    do {
        Ov025_SetEntrySlotsVisible(a, Ov025_FindEntryById(a, i), 0);
        i++;
    } while (i <= 0xdc);
}
