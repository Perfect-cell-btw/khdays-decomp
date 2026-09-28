extern int Slot_ClearFlagBit1();

void Ov026_ReleaseTwoSlots(int a, int *b) {
    int i;
    int v;
    for (i = 0; i < 2; i++) {
        v = b[i + 5];
        if (v != -1) {
            Slot_ClearFlagBit1(a, v);
        }
    }
}
