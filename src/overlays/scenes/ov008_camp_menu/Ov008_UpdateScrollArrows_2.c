/* Show/hide two slot groups based on the scroll extent (0x60 - field 0x164) and the drag delta
 * param_2: group 0x40 visible while scrolling right (delta > 0), group 0x41 visible while there is
 * still room to scroll (delta < extent). */
extern int Ov008_GetCtxBlock4a80(void);
extern int Ov008_FindEntryById(int ctx, int id);
extern void Ov008_SetEntrySlotsVisible(int ctx, int entry, int visible);

void Ov008_UpdateScrollArrows_2(int param_1, int param_2) {
    int ctx = Ov008_GetCtxBlock4a80();
    int extent = 0x60 - *(int *)(param_1 + 0x164);
    int vis1 = 0;
    int vis2 = 0;
    int entry;
    if (extent > 0 && param_2 > 0) {
        vis1 = 1;
    }
    if (extent > 0 && param_2 < extent) {
        vis2 = 1;
    }
    entry = Ov008_FindEntryById(ctx, 0x40);
    Ov008_SetEntrySlotsVisible(ctx, entry, vis1);
    entry = Ov008_FindEntryById(ctx, 0x41);
    Ov008_SetEntrySlotsVisible(ctx, entry, vis2);
}
