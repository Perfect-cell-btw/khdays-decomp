/* When the menu is ready and not busy, rebuilds the page's query list for the key and sorts it. */

extern int Ov025_GetPageA();
extern int Ov025_GetCtxObject9634();
extern int Ov025_GetCtxObject9630();
extern void Ov025_RebuildQueryList();
extern void Ov025_SortListByKey();

void Ov025_DispatchIfReady_dcdc(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3) {
    int x = Ov025_GetPageA();
    if (Ov025_GetCtxObject9634() != 0) return;
    if (Ov025_GetCtxObject9630() == 0) return;
    Ov025_RebuildQueryList(x + 0x13fc, arg0);
    Ov025_SortListByKey(x);
}
