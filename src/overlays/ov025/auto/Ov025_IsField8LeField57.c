int Ov025_IsField8LeField57(char *a, char *b) {
    return *(unsigned short *)(b + 8) <= *(unsigned char *)(a + 0x57);
}
