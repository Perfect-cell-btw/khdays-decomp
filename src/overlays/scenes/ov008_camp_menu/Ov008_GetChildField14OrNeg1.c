int Ov008_GetChildField14OrNeg1(char *obj) {
    if (obj != 0) {
        return *(int *)(*(char **)(obj + 0xc) + 0x14);
    }
    return -1;
}
