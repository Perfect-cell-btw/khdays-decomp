/* Picks the animation id (0xa3, 0xa4, 0xa5, 0xa2) from the slot kind byte at +0x918. */

int Ov098_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x14: return 0xa3;
        case 0x15: return 0xa4;
        case 0x16: return 0xa5;
        default: return 0xa2;
    }
}
