extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_FreeDetailBuffer(int arg0) {
    int p = *(int *)(arg0 + 0x174);
    if (p == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(p);
    *(int *)(arg0 + 0x174) = 0;
}
