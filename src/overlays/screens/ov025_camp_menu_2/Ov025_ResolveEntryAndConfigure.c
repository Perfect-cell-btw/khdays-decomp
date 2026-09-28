extern int Ov025_FindEntryById();
extern void Ov025_PushSubitemSet();
extern void Ov025_SetEntrySlotsVisible();

void Ov025_ResolveEntryAndConfigure(int arg0, int arg1, int arg2) {
    int r = Ov025_FindEntryById(arg0, arg1);
    Ov025_PushSubitemSet(arg0, r, arg2 == 0);
    Ov025_SetEntrySlotsVisible(arg0, r, arg2);
}
