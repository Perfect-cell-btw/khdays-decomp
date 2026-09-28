int Ov008_GetField84Bit1(int a, char *obj) {
    return (int)(((unsigned)*(int *)(obj + 0x84) << 30) >> 31);
}
