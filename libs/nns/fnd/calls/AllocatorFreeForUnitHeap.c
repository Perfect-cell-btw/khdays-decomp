/* NitroSystem fnd (allocator.c): AllocatorFreeForUnitHeap -- paired with AllocatorAllocForUnitHeap in the allocator function table. */
extern void *NNS_FndFreeToUnitHeap();

void *AllocatorFreeForUnitHeap(void **allocator, void *block) {
    return NNS_FndFreeToUnitHeap(allocator[1], block);
}
