/* NitroSystem fnd (expheap.c): NNS_FndDestroyExpHeap -- NNSi_FndFinalizeHeap(heap); sits right before NNS_FndAllocFromExpHeapEx. */
extern void *NNSi_FndFinalizeHeap();

void *NNS_FndDestroyExpHeap(void *arg0) {
    return NNSi_FndFinalizeHeap(arg0);
}
