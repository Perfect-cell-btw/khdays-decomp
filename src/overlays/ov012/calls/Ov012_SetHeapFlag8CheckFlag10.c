extern int NNSi_FndGetCurrentRootHeap();
extern void StoreGlobalPairAt10();

int Ov012_SetHeapFlag8CheckFlag10(void) {
    unsigned short *p = (unsigned short *)(NNSi_FndGetCurrentRootHeap() + 2);
    unsigned int v = *p | 8;
    *p = v;
    if ((v & 0x10) == 0) return 0;
    StoreGlobalPairAt10(5, 0x190);
    return -2;
}
