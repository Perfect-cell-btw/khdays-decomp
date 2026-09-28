/* Runs SlotTable_GetEntryFrame on the first of the two ids at +0x14 that is not -1, and returns its
 * result (0 when both slots are empty).
 *
 * The table access is an ARRAY INDEX with 0x14 folded in (tbl[i + 5]); as
 * `(char *)tbl + i * 4 + 0x14` mwcc builds a second induction variable (+8 bytes). */
extern int SlotTable_GetEntryFrame(int a, int b);
int Ov005_GetFirstValidSlotFrame(int a, int *tbl) {
    int i;
    int r;
    int m1;
    int v;
    r = 0;
    i = r;
    m1 = -1;
    do {
        v = tbl[i + 5];
        if (v != m1) {
            r = SlotTable_GetEntryFrame(a, v);
            break;
        }
        i = i + 1;
    } while (i < 2);
    return r;
}
