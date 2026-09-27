/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to NNSi_FndFreeFromDefaultHeap. */
extern void *NNSi_FndFreeFromDefaultHeap();

void *func_ov024_02083d00() {
    return NNSi_FndFreeFromDefaultHeap();
}
