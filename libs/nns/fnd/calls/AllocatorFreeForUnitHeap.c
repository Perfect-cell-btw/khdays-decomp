/* NitroSystem fnd (allocator.c): AllocatorFreeForUnitHeap -- paired with AllocatorAllocForUnitHeap in the allocator function table. */
extern void *func_02010d24();

void *AllocatorFreeForUnitHeap(void **allocator, void *block) {
    return func_02010d24(allocator[1], block);
}
