/* Stores the value in both the current (+0) and saved (+0x20) words. */

void Ov008_SetWord0And20(char *obj, int v) {
    *(int *)obj = v;
    *(int *)(obj + 0x20) = v;
}
