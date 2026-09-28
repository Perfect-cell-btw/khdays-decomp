void Ov022_ResetBlock94c(char *obj) {
    int i;
    *obj = 0;
    *(int *)(obj + 0x94c) = 0;
    for (i = 0; i < 5; i++) obj[0x94c + 4 + i] = -1;
}
