/* Init the 0xc-byte record at param_1: zero it, acquire resource 0xe from param_2, store
 * the handle at +0, its second word at +4, and (handle + its first word) at +8. */
extern void MI_CpuFill8(void *dst, int val, int size);
extern int Archive_LoadFile(int a, int b);
void Ov005_InitResourceRecord(int param_1, int param_2) {
    int r, lo;
    MI_CpuFill8((void *)param_1, 0, 0xc);
    r = Archive_LoadFile(param_2, 0xe);
    *(int *)param_1 = r;
    lo = *(int *)r;
    *(int *)(param_1 + 4) = *(int *)(r + 4);
    *(int *)(param_1 + 8) = *(int *)param_1 + lo;
}
