/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to NNS_FndFreeToAllocator. */
extern void *NNS_FndFreeToAllocator();

void *func_0201696c() {
    return NNS_FndFreeToAllocator();
}
