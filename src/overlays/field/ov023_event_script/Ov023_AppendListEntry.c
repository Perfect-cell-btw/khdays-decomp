extern int Ov023_CountSubPanelEntries(int obj);
/* Append to the object's list (obj+0x45c, stride 0xc, count via Ov023_CountSubPanelEntries): store the
 * value at +4 and mark the entry type 2 at +8. */
void Ov023_AppendListEntry(int obj, int value) {
    int idx = Ov023_CountSubPanelEntries(obj);
    int entry = obj + 0x45c + idx * 0xc;
    *(int *)(entry + 4) = value;
    *(int *)(entry + 8) = 2;
}
