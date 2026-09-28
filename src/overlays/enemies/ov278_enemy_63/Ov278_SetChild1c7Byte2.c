void Ov278_SetChild1c7Byte2(char *obj) {
    char *p = *(char **)*(char **)(obj + 4);
    *(char *)(p + 0x1c7) = 2;
}
