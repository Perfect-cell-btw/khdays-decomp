/* Sets bit 1 on the object's two slots that are in use. */

extern int Slot_SetFlagBit1();

void Ov005_ReleaseTwoSlots_2(int a, int *b) {
    int i;
    int v;
    for (i = 0; i < 2; i++) {
        v = b[i + 5];
        if (v != -1) {
            Slot_SetFlagBit1(a, v);
        }
    }
}
