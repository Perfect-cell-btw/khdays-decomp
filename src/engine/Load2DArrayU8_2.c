/* Returns a byte from a global 2D table (0x104-byte rows). */

extern int data_0204c690;

int Load2DArrayU8_2(int arg0, int arg1) {
    return *(unsigned char *)((char *)&data_0204c690 + arg0 * 0x104 + arg1);
}
