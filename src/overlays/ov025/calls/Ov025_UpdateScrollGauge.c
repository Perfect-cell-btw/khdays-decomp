/* Ov025_UpdateScrollGauge -- Ov008_UpdateScrollGauge (208 B, 8 relocs).
 * Recomputes the menu list's scroll gauge after the entry list changes. Counts the objects in the
 * list at self+0x1cc, derives a per-step scale = 0x800 / (count * 2) (func_02020400), clamps it to
 * [0x20, 0x80] and stores it at self+0x4c. Then it toggles the visibility of the 14 gauge segments
 * (entry ids 0x30..0x3d) in the scene block: a segment is shown while its index (id - 0x30) is
 * within (scale - 0x20) / 8, otherwise hidden. A direct dependency of the menu page-rebuild tick
 * (Ov008_RefreshEquipPanel) and of Ov008_AddListEntry.
 * The scale is written to self+0x4c three times (once per clamp step, matching the ROM), and the
 * loop-invariant (scale-0x20)/8 keeps its final arithmetic shift inside the per-iteration compare. */
extern int  func_02020400(int a, int b);
extern int  NNS_FndGetNextListObject(void *list, int obj);
extern int  Ov025_GetBlock4a80(void);
extern int  Ov025_FindEntryById(int ctx, int id);
extern void Ov025_SetEntrySlotsVisible(int obj, int entry, int n);

void Ov025_UpdateScrollGauge(int self)
{
    int count = 0;
    int q, block, base, id, entry, obj;

    for (obj = NNS_FndGetNextListObject((void *)(self + 0x1cc), 0); obj != 0;
         obj = NNS_FndGetNextListObject((void *)(self + 0x1cc), obj))
        count++;
    q = func_02020400(0x800, count << 1);
    *(int *)(self + 0x4c) = q;
    if (q <= 0x20)
        q = 0x20;
    *(int *)(self + 0x4c) = q;
    if (q >= 0x80)
        q = 0x80;
    *(int *)(self + 0x4c) = q;
    block = Ov025_GetBlock4a80();
    base = *(int *)(self + 0x4c) - 0x20;
    for (id = 0x30; id <= 0x3d; id++) {
        if (id - 0x30 <= base / 8) {
            entry = Ov025_FindEntryById(block, id);
            Ov025_SetEntrySlotsVisible(block, entry, 1);
        } else {
            entry = Ov025_FindEntryById(block, id);
            Ov025_SetEntrySlotsVisible(block, entry, 0);
        }
    }
}
