extern int Slot_ForwardToEntry();

void Ov009_ReleaseTwoSlotsEx_2(int r0, int *r1, int r2) {
    int i;
    int v;
    for (i = 0; i < 2; i++) {
        v = r1[i + 5];
        if (v != -1) {
            Slot_ForwardToEntry(r0, v, r2);
        }
    }
}
