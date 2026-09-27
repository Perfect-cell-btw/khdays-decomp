/* NitroSystem fnd (expheap.c): NNS_FndDestroyExpHeap -- NNSi_FndFinalizeHeap(heap); sits right before NNS_FndAllocFromExpHeapEx. */
extern void *NNSi_FndFinalizeHeap();

void *NNS_FndDestroyExpHeap() {
    return NNSi_FndFinalizeHeap();
}
