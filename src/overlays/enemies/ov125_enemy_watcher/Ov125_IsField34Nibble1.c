/* Whether the 4-bit field of the word at +0x34 is 1. */

int Ov125_IsField34Nibble1(char *obj) {
    return (*(int *)(obj + 0x34) << 28 >> 28) == 1;
}
