/* Allocates via Archive_LoadFile(arg1, arg2); if NNS_G2dGetUnpackedPaletteData(r, this) succeeds
 * returns r, else frees r via NNSi_FndFreeFromDefaultHeap and returns 0. */

extern void *Archive_LoadFile();
extern int NNS_G2dGetUnpackedPaletteData();
extern void NNSi_FndFreeFromDefaultHeap();

void *AllocAndRegisterOrFree2(int this_, int arg1, int arg2) {
    void *r = Archive_LoadFile(arg1, arg2);
    if (r == 0) goto ret0;
    if (NNS_G2dGetUnpackedPaletteData(r, this_) != 0) return r;
    NNSi_FndFreeFromDefaultHeap(r);
ret0:
    return 0;
}
