/* Moves the element's two slots (+0x14, +0x18) that are set to the position. */

extern int Slot_SetPosition();

void Ov005_ReleaseTwoSlotsEx(int a, int *b, int c) {
    int i;
    for (i = 0; i < 2; i++) {
        int v = b[i + 5];
        if (v != -1) {
            Slot_SetPosition(a, v, c);
        }
    }
}
