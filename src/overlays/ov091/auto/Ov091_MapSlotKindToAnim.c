/* Picks the animation id (0x85, 0x86, 0x84) from the slot kind byte at +0x918. */

int Ov091_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 1: return 0x85;
        case 2: return 0x86;
        default: return 0x84;
    }
}
