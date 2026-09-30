/* Construct the 0x24-byte manager at param_1 from the config at param_2: zero it, init its
 * embedded list (link offset 0x4c), load the default config table, cache count (+0xc) and
 * acquire resource 0xe (+0x14), then run the sub-init with the two config words. */
extern void MI_CpuFill8(void *dst, int val, int size);
extern void NNS_FndInitList(int list, int offset);
extern void Ov005_InitResourceRecord(int a, void *b);
extern int Archive_LoadFile(int a, int b);
extern void Ov005_QueryFieldBySelector(int a, int b, int c);
extern int gOv005UiCmStrWorldIdTextPath;
void Ov005_InitObjectWithList(int param_1, int param_2) {
    MI_CpuFill8((void *)param_1, 0, 0x24);
    NNS_FndInitList(param_1 + 0x18, 0x4c);
    Ov005_InitResourceRecord(param_1, &gOv005UiCmStrWorldIdTextPath);
    *(int *)(param_1 + 0xc) = *(int *)(param_2 + 8);
    *(int *)(param_1 + 0x14) = Archive_LoadFile(*(int *)param_2, 0xe);
    Ov005_QueryFieldBySelector(param_1, *(int *)(param_2 + 8), *(int *)(param_2 + 4));
}
