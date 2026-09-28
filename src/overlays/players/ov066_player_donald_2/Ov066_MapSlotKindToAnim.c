/* Picks the animation id (0xad, 0xae, 0xac) from the slot kind byte at +0x918. */

int Ov066_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 1: return 0xad;
        case 2: return 0xae;
        default: return 0xac;
    }
}
