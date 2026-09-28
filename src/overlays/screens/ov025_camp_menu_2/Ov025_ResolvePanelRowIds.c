/* Ov025_ResolvePanelRowIds -- resolve the panel's 19 row ids (tags 5, 6, then 7..0x17) from the item
 * table at ctx+0xb8 into the slot array at ctx+8. */
extern int Ov025_GetPageA(void);
extern int Ov025_FindEntryById(int table, int tag);

void Ov025_ResolvePanelRowIds(void) {
    int ctx = Ov025_GetPageA();
    int *slots = (int *)(ctx + 8);
    int i;
    slots[0] = Ov025_FindEntryById(*(int *)(ctx + 0xb8), 5);
    slots[1] = Ov025_FindEntryById(*(int *)(ctx + 0xb8), 6);
    i = 0;
    do {
        slots[i + 2] = Ov025_FindEntryById(*(int *)(ctx + 0xb8), i + 7);
        i = i + 1;
    } while (i < 0x11);
}
