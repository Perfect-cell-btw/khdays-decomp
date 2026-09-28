/* Build a record via ov000_02056094, zero it (0x10 bytes), store the key/owner, register it via
 * 02011a6c, mark it active (+0xc=1) and return it. */
extern int Ov002_FindFirstUnusedElem(int a);
extern void MI_CpuFill8(void *dst, int val, int size);
extern void NNS_G2dGetUnpackedScreenData(int a, int b);
int Ov002_AllocResourceEntry(int a, int b, unsigned short c) {
    int obj = Ov002_FindFirstUnusedElem(a);
    MI_CpuFill8((void *)obj, 0, 0x10);
    *(unsigned short *)(obj) = c;
    *(int *)(obj + 4) = b;
    NNS_G2dGetUnpackedScreenData(b, obj + 8);
    *(int *)(obj + 0xc) = 1;
    return obj;
}
