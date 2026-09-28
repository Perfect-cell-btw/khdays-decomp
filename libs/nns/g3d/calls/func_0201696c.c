/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to NNS_FndFreeToAllocator. */
extern void *NNS_FndFreeToAllocator();

void *func_0201696c(void *allocator, void *block) {
    return NNS_FndFreeToAllocator(allocator, block);
}
