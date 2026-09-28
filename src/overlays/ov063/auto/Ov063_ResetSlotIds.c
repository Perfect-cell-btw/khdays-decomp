/* Sets the eight slot ids at +0x160 to -1. */

void Ov063_ResetSlotIds(short *p) {
    int i;
    for (i = 0; i < 8; i++) {
        p[0x160 / 2 + i] = -1;
    }
}
