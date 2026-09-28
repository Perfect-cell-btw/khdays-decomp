/* Picks the animation id (0x88, 0x87) from the slot kind byte at +0x918. */

int Ov084_MapSlotKindToAnim(unsigned char *p) {
    if (p[0x918] == 1) return 0x88;
    return 0x87;
}
