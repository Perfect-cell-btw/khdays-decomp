/* Releases the character's effect sequences (the main one and six slots), then frees its effect
 * stream and buffer. */

extern void ReleaseField74AndCleanup(int a);
extern void func_ov022_02091228(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern int data_ov065_020b7340;

void Ov065_DestroyNodesAndFree(int self) {
    int base = *(int *)&data_ov065_020b7340 + 0x2c80;
    int i;
    char *p;
    ReleaseField74AndCleanup(base + 4);
    p = (char *)(base + 0x12c);
    for (i = 0; i < 6; i++, p += 0x120) {
        ReleaseField74AndCleanup((int)p);
    }
    func_ov022_02091228(*(int *)(self + 0x2000 + 0x644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(self + 0x2000 + 0x644));
}
