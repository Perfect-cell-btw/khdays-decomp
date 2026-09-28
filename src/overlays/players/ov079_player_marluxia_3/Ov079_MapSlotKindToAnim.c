/* Picks the animation id (0x97, 0x98, 0x99, 0x96) from the slot kind byte at +0x918. */

int Ov079_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x13: return 0x97;
        case 0x14: return 0x98;
        case 0x15: return 0x99;
        default: return 0x96;
    }
}
