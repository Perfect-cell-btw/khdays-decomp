/* Picks the animation id (0x81, 0x82, 0x83, 0x80) from the slot kind byte at +0x918. */

int Ov093_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x14: return 0x81;
        case 0x15: return 0x82;
        case 0x16: return 0x83;
        default: return 0x80;
    }
}
