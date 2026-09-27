/* NitroSystem fnd (allocator.c): AllocatorAllocForFrmHeap -- paired with the empty AllocatorFreeForFrmHeap in the allocator function table. */
extern void *NNS_FndAllocFromFrmHeapEx();

void *AllocatorAllocForFrmHeap(void **allocator, unsigned int size) {
    return NNS_FndAllocFromFrmHeapEx(allocator[1], size, allocator[2]);
}
