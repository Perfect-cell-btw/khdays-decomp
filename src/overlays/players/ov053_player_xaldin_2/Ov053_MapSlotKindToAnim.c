/* Picks the animation id (0x7d, 0x7e, 0x7f, 0x7c) from the slot kind byte at +0x918. */

int Ov053_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x14: return 0x7d;
        case 0x15: return 0x7e;
        case 0x16: return 0x7f;
        default: return 0x7c;
    }
}
