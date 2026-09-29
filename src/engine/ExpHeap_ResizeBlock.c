/* Resizes a memory block of an expanded heap (NNS_FndResizeForMBlockExpHeap). */

extern int NNS_FndResizeForMBlockExpHeap();

int ExpHeap_ResizeBlock(int *heap, void *memoryBlock, int size) {
    return NNS_FndResizeForMBlockExpHeap(*heap, memoryBlock, size);
}
