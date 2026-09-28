/* Frees the object's five buffers. */

extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_FreeFiveBuffers(int arg0) {
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x208c));
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x2088));
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x2084));
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x2080));
    NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x207c));
}
