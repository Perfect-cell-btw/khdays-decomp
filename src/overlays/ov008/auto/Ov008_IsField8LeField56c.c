int Ov008_IsField8LeField56c(char *a, char *b) {
    return *(unsigned short *)(b + 8) <= *(unsigned char *)(a + 0x56c);
}
