extern int Slot_SetPosition();

void Ov000_SetEntryPosition(int a, int *b, int c) {
    int i;
    for (i = 0; i < 2; i++) {
        int v = b[i + 5];
        if (v != -1) {
            Slot_SetPosition(a, v, c);
        }
    }
}
