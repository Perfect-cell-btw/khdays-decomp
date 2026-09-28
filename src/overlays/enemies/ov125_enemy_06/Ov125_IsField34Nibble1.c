int Ov125_IsField34Nibble1(char *obj) {
    return (*(int *)(obj + 0x34) << 28 >> 28) == 1;
}
