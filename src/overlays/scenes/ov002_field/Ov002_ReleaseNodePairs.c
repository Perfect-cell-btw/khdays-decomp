extern void NNSi_FndFreeFromDefaultHeap();

void Ov002_ReleaseNodePairs(int arg0) {
    int p = *(int *)(arg0 + 0x1c);
    if (p != 0) {
        NNSi_FndFreeFromDefaultHeap(p);
        *(int *)(arg0 + 0x1c) = 0;
    }
}
