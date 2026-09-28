int Ov047_MapSlotKindToAnim(unsigned char *p) {
    switch (p[0x918]) {
        case 1: return 0xad;
        case 2: return 0xae;
        default: return 0xac;
    }
}
