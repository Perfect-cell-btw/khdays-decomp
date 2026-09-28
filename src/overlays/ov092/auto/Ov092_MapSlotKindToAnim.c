/* Picks the animation id (0x9b, 0x9c, 0x9d, 0x9a) from the slot kind byte at +0x918. */

int Ov092_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x13: return 0x9b;
        case 0x14: return 0x9c;
        case 0x15: return 0x9d;
        default: return 0x9a;
    }
}
