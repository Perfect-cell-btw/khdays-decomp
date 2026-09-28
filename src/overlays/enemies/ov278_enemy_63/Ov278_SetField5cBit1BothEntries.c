void Ov278_SetField5cBit1BothEntries(char *obj) {
    int *base = *(int **)(obj + 4);
    int i = 0;
    do {
        int *elem = (int *)base[i + 1];
        *(int *)((char *)elem + 0x5c) |= 2;
        i++;
    } while (i < 2);
}
