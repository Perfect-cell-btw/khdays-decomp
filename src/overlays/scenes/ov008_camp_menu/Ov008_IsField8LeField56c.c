/* Whether the entry's 16-bit value (+8) is at most the limit byte of the owner. */

int Ov008_IsField8LeField56c(char *a, char *b) {
    return *(unsigned short *)(b + 8) <= *(unsigned char *)(a + 0x56c);
}
