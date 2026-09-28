/* Releases the element's two slot handles (+0x14, +0x18) that are set. */

extern int Slot_ClearFlagBit1();

void Ov025_ReleaseTwoSlots(int a, int *b) {
    int i;
    int v;
    for (i = 0; i < 2; i++) {
        v = b[i + 5];
        if (v != -1) {
            Slot_ClearFlagBit1(a, v);
        }
    }
}
