/* Returns a byte from a global 2D table (0x104-byte rows, 2-byte columns). */

extern int data_0204c714;

int Load2DArrayU8(int arg0, int arg1) {
    return *(unsigned char *)((char *)&data_0204c714 + arg0 * 0x104 + arg1 * 2);
}
