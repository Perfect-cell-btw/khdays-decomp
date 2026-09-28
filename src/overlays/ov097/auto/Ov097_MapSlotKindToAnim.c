/* Picks the animation id (0xb3, 0xb4, 0xb2) from the slot kind byte at +0x918. */

int Ov097_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 1: return 0xb3;
        case 2: return 0xb4;
        default: return 0xb2;
    }
}
