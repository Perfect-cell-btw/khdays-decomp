/* Picks the animation id (0x75, 0x76, 0x77, 0x74) from the slot kind byte at +0x918. */

int Ov032_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 0x13: return 0x75;
        case 0x14: return 0x76;
        case 0x15: return 0x77;
        default: return 0x74;
    }
}
