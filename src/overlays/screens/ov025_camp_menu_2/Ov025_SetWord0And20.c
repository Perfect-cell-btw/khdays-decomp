void Ov025_SetWord0And20(char *obj, int v) {
    *(int *)obj = v;
    *(int *)(obj + 0x20) = v;
}
