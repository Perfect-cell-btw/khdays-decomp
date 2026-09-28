/* Shows an entry with a frame, or hides it for a negative frame. */

extern int Ov025_GetContext();
extern int Ov025_FindEntryById();
extern void Ov025_SetEntrySlotsVisible();
extern void Ov025_ReleaseTwoSlotsEx_2();

void Ov025_ConfigureTagBySign(int arg0, unsigned int arg1) {
    int a = Ov025_GetContext();
    int e = Ov025_FindEntryById(a, arg0);
    if ((int)arg1 >= 0) {
        Ov025_SetEntrySlotsVisible(a, e, 1);
        Ov025_ReleaseTwoSlotsEx_2(a, e, arg1 & 0xffff);
        return;
    }
    Ov025_SetEntrySlotsVisible(a, e, 0);
}
