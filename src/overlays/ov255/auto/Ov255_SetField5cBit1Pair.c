void Ov255_SetField5cBit1Pair(char *obj) {
    int *a = *(int **)(obj + 4);
    *(int *)(a[0] + 0x5c) |= 2;
    *(int *)(a[1] + 0x5c) |= 2;
}
