/* Allocator vtable hook: frees `block` from the expanded heap stored at allocator+4. */
extern void *NNS_FndFreeToExpHeap();

void *AllocatorFreeForExpHeap(void **allocator, void *block) {
    return NNS_FndFreeToExpHeap(allocator[1], block);
}
