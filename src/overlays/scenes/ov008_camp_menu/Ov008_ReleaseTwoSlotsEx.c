/* Forwards the element's two slot handles (+0x14, +0x18) that are set to their slot entries with
 * the value. */

extern int Slot_ForwardToEntry();

void Ov008_ReleaseTwoSlotsEx(int r0, int *r1, int r2) {
    int i;
    int v;
    for (i = 0; i < 2; i++) {
        v = r1[i + 5];
        if (v != -1) {
            Slot_ForwardToEntry(r0, v, r2);
        }
    }
}
