extern char *data_ov008_02090fac;
extern char *data_0204be18;
extern int Ov008_FindEntryByTag(void *p, unsigned int id);
extern void Ov008_TagTracker_InvokeCallback(void *p, int cell);
extern void Obj_InvokeInnerVtable8(void *p, int a, int b, int c, int d);
extern void Ov008_ShowThreeDigitCells(int handle, unsigned int value, void *cells);

/* First-time setup of the counter panel: loads its background, lays it out and fills in the two
 * totals from the save header. */
void Ov008_UpdateCounterPanel(void) {
    char *st = *(char **)&data_ov008_02090fac;
    char *panel = st + 0xc324;
    char *layout = st + 0xc1d8;
    int handle = *(int *)(st + 0xbfb4);
    if (*(int *)(st + 0xc324) == 0) {
        Ov008_TagTracker_InvokeCallback(st + 0x5c, Ov008_FindEntryByTag(st + 0x5c, 0x3f5));
        Obj_InvokeInnerVtable8(layout, 0, 0, 0xb0, 0x30);
        *(int *)panel = 1;
    }
    Ov008_ShowThreeDigitCells(handle, *(unsigned short *)(*(char **)&data_0204be18 + 0x196a), panel + 8);
    Ov008_ShowThreeDigitCells(handle, *(unsigned short *)(*(char **)&data_0204be18 + 0x1968), panel + 0x14);
}
