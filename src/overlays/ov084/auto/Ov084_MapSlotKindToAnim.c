int Ov084_MapSlotKindToAnim(unsigned char *p) {
    if (p[0x918] == 1) return 0x88;
    return 0x87;
}
