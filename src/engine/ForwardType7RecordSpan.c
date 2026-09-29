/* Finds the archive's texture member (type 7) and registers its texture data span. */

extern int Archive_GetMember(int a, int b, int c);
extern int NNS_G3dGetTex(int entry);
extern void ExpHeap_ResizeBlock(int a, int b, int c, int d);

void ForwardType7RecordSpan(int param_1, int param_2, int param_3) {
    int entry = Archive_GetMember(param_1, 7, 0);
    int base;
    if (entry == 0) return;
    base = NNS_G3dGetTex(entry);
    if (base == 0) return;
    ExpHeap_ResizeBlock(param_2, param_1, base + *(int *)(base + 0x14) - param_1, param_3);
}
