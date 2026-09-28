void Ov044_ResetSlotIds(short *p) {
    int i;
    for (i = 0; i < 8; i++) {
        p[0x160 / 2 + i] = -1;
    }
}
