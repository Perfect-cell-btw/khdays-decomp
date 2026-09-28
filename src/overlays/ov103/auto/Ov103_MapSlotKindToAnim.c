/* Picks the animation id (0xb0, 0xb1, 0xaf) from the slot kind byte at +0x918. */

int Ov103_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 1: return 0xb0;
        case 2: return 0xb1;
        default: return 0xaf;
    }
}
