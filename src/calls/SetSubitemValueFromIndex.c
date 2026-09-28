extern int List_Nth(int a, int b);
extern int NNS_G2dGetAnimSequenceByIdx(void *a, int b);
extern void NNS_G2dSetCellAnimationSequence(int a, int b);

void SetSubitemValueFromIndex(int param_1, int param_2, unsigned param_3) {
    int r;
    if (param_2 < 0) return;
    r = List_Nth(param_1, *(int *)(param_1 + param_2 * 0x8c + 0x78));
    r = NNS_G2dGetAnimSequenceByIdx(*(unsigned short **)(r + 0x10), param_3 & 0xffff);
    NNS_G2dSetCellAnimationSequence(param_1 + 0x18 + param_2 * 0x8c, r);
}
