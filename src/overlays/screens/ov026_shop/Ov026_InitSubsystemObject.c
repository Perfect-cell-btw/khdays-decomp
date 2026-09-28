/* Construct a 0x4a80-byte subsystem object: zero it, set the +0x4a78 tag to 0xf0, pick a
 * pool budget by the global mode (data_0204c058: 0=>0x1e, 1=>0x14, 2=>0x3c), allocate it
 * (func_02020400(0x3c000, budget)) at +0x4a74, init the sub-object at +0x4a54 and the list
 * at +0x4a38. If a template (param_2) is given, apply it (Ov026_InitFromDescAndMark) and, when it
 * carries a non-empty payload (param_2[5], param_2[4]>0), load it via Ov026_LoadBlockProcessAndFree. */
extern void MI_CpuFill8(void *dst, int val, unsigned int n);
extern int func_02020400(int a, int b);
extern void Tween_Clear(void *p);
extern void NNS_FndInitList(void *list, int a);
extern void Ov026_InitFromDescAndMark(char *obj, int *tmpl);
extern void Ov026_LoadBlockProcessAndFree(char *obj, char *data, int count);
extern unsigned char data_0204c058;
int Ov026_InitSubsystemObject(char *param_1, int *param_2, int param_3, int param_4) {
    int budget;
    MI_CpuFill8(param_1, 0, 0x4a80);
    *(unsigned short *)(param_1 + 0x4a78) = 0xf0;
    switch (data_0204c058) {
        case 1: budget = 0x14; break;
        case 0: budget = 0x1e; break;
        case 2: budget = 0x3c; break;
    }
    *(int *)(param_1 + 0x4a74) = func_02020400(0x3c000, budget);
    Tween_Clear(param_1 + 0x4a54);
    NNS_FndInitList(param_1 + 0x4a38, 0);
    if (param_2 != 0) {
        Ov026_InitFromDescAndMark(param_1, param_2);
        if (param_2[5] != 0 && param_2[4] > 0) {
            Ov026_LoadBlockProcessAndFree(param_1, (char *)param_2[5], param_2[4]);
        }
    }
    return 1;
}
