/* Picks the animation id (0x8a, 0x8b, 0x8c, 0x89) from the slot kind byte at +0x918. */

int Ov077_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x14: return 0x8a;
        case 0x15: return 0x8b;
        case 0x16: return 0x8c;
        default: return 0x89;
    }
}
