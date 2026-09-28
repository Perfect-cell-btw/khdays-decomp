/* Returns a field (+0xdc) of the object a global points to, or 0 when there is none. */

extern int data_0204be08;

int LoadGlobalPtr4FieldDcOrZero(void) {
    int p = *(int *)((char *)&data_0204be08 + 4);
    if (p == 0) return 0;
    return *(int *)(p + 0xdc);
}
