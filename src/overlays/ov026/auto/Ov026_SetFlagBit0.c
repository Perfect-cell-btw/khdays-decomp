/* Sets bit 0 of the object's flag byte (+0x2c) to the value. */

void Ov026_SetFlagBit0(unsigned char *r0, int r1) {
    r0[0x2c] = (r0[0x2c] & ~1) | ((unsigned char)r1 & 1);
}
