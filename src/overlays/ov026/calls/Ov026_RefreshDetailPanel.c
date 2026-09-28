extern char *data_ov026_02091368;
extern void Obj_InvokeInnerVtable8(void *p, int a, int b, int c, int d);
extern void Slot_UnlinkIfLinked(int handle, int cell);

/* Re-lays out the detail panel and refreshes its six cells. */
void Ov026_RefreshDetailPanel(void) {
    int handle;
    char *st = *(char **)&data_ov026_02091368;
    char *cells = st + 0xc4f4;
    handle = *(int *)(st + 0xbfb0);
    Obj_InvokeInnerVtable8(st + 0xc160, 0x28, 0x38, 0xb0, 0x40);
    Slot_UnlinkIfLinked(handle, *(int *)(st + 0xc5e0));
    Slot_UnlinkIfLinked(handle, *(int *)(st + 0xc5e4));
    Slot_UnlinkIfLinked(handle, *(int *)(st + 0xc5e8));
    Slot_UnlinkIfLinked(handle, *(int *)(st + 0xc5ec));
    Slot_UnlinkIfLinked(handle, *(int *)(cells + 0x50));
    Slot_UnlinkIfLinked(handle, *(int *)(cells + 0x4c));
    *(int *)(st + 0xc320) = 0;
}
