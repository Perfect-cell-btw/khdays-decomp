/* Releases the two optional blocks at +0x2f0/+0x2f4 and tears down every embedded
 * sub-object: the three singles at +0xac / +0xe8 / +0x124 and the five 0x3c-byte entries
 * from +0x160.
 *
 * `i` has to be declared before the cursor so the loop colours i=r4 / p=r5 as the ROM does. */
extern void NNSi_FndFreeFromDefaultHeap(int p);
extern void FreeAllListNodeSubBuffers(char *p);

void Ov025_ReleaseSubObjects(char *self) {
    int i;
    char *p;
    if (*(int *)(self + 0x2f0) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)(self + 0x2f0));
        *(int *)(self + 0x2f0) = 0;
    }
    FreeAllListNodeSubBuffers(self + 0xac);
    if (*(int *)(self + 0x2f4) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)(self + 0x2f4));
        *(int *)(self + 0x2f4) = 0;
    }
    FreeAllListNodeSubBuffers(self + 0xe8);
    FreeAllListNodeSubBuffers(self + 0x124);
    p = self + 0x160;
    i = 0;
    do {
        FreeAllListNodeSubBuffers(p);
        i = i + 1;
        p = p + 0x3c;
    } while (i < 5);
}
