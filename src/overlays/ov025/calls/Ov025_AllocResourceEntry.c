extern int Ov025_FindFirstUnusedElem();
extern void MI_CpuFill8();
extern void NNS_G2dGetUnpackedScreenData();

unsigned int * Ov025_AllocResourceEntry(int arg0, unsigned int arg1, unsigned short arg2) {
    unsigned int *p = (unsigned int *)Ov025_FindFirstUnusedElem(arg0);
    MI_CpuFill8(p, 0, 0x10);
    *(unsigned short *)p = arg2;
    p[1] = arg1;
    NNS_G2dGetUnpackedScreenData(arg1, p + 2);
    p[3] = 1;
    return p;
}
