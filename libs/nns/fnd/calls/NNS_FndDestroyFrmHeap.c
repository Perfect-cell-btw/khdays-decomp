/* NitroSystem fnd (frmheap.c): NNS_FndDestroyFrmHeap -- NNSi_FndFinalizeHeap(heap); sits right before NNS_FndAllocFromFrmHeapEx. */
extern void *NNSi_FndFinalizeHeap();

void *NNS_FndDestroyFrmHeap() {
    return NNSi_FndFinalizeHeap();
}
