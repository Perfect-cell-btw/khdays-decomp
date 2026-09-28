/* Picks the animation id (0x6b, 0x56, 0x55, 0x55, v + 0x55) from the slot kind byte at +0x918. */

int Ov063_MapSlotKindToAnim(unsigned char *p) {
    unsigned char v = p[0x918];
    switch (v) {
        case 0x1a: return 0x6b;
        case 0x1b: return 0x56;
        case 0: return 0x55;
        case 1: return 0x55;
        default: return v + 0x55;
    }
}
