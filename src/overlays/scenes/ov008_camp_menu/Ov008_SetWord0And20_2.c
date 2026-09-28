void Ov008_SetWord0And20_2(char *obj, int v) {
    *(int *)obj = v;
    *(int *)(obj + 0x20) = v;
}
