/* Ov026_SetupMenuScreen -- Ov008_SetupMenuScreen (216 B, 8 relocs).
 * Initializes a menu screen from the shared panel context (*data_ov026_02091368): sets up the
 * display region at ctx+0xc214 (Obj_InvokeInnerVtable8 8,0x10,0xb6,0x70), zero-clears the 0x400-byte
 * buffer at ctx+0x728, sets bit 1 of the flags at ctx+0x2aac, then registers eight entries
 * (arr[1..8] at ctx+0xc4f4) into the handle at ctx+0xbfb4 via Slot_UnlinkIfLinked. Clears three
 * trailing fields and disables widget id 6 (ctx+0x7530), then Ov026_RedrawBothColumns.
 * NOTE: the clear buffer's address is written as (u8 (*)[0x480])(ctx+0x2a8) + 1 so mwcc emits the
 * base(ctx+0x2a8) + 0x480 split the original uses, rather than folding ctx+0x728 into one add. */
typedef unsigned char u8;

extern char *data_ov026_02091368;
extern void  Obj_InvokeInnerVtable8(void *dst, int a, int b, int c, int d);
extern void  INITi_CpuClear32_0x01ff86fc(int value, void *dst, unsigned int size);
extern void  Slot_UnlinkIfLinked(void *a, int v);
extern void *Ov026_FindEntryById(void *ctx, int id);
extern void  Ov026_SetEntrySlotsVisible(void *ctx, void *widget, int flag);
extern void  Ov026_RedrawBothColumns(void);

void Ov026_SetupMenuScreen(void)
{
    char *ctx = data_ov026_02091368;
    int  *arr = (int *)(ctx + 0xc4f4);
    void *handle = *(void **)(ctx + 0xbfb4);
    char *w = ctx + 0x7530;
    int i;

    Obj_InvokeInnerVtable8(ctx + 0xc214, 8, 0x10, 0xb6, 0x70);
    INITi_CpuClear32_0x01ff86fc(0, (u8 (*)[0x480])(ctx + 0x2a8) + 1, 0x400);
    *(int *)(ctx + 0x2aac) |= 2;
    for (i = 0; i < 4; i++) {
        Slot_UnlinkIfLinked(handle, arr[i + 1]);
        Slot_UnlinkIfLinked(handle, arr[i + 5]);
    }
    arr[0xa] = 0;
    *(int *)(ctx + 0xc31c) = 0;
    *(int *)(ctx + 0xc314) = 0;
    Ov026_SetEntrySlotsVisible(w, Ov026_FindEntryById(w, 6), 0);
    Ov026_RedrawBothColumns();
}
