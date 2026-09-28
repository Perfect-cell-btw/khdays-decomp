/* Ov008_FreeScratchBuffers -- free the five scratch buffers of an ov008 object (obj+0x207c..0x208c). */
extern void NNSi_FndFreeFromDefaultHeap(void *p);

void Ov008_FreeScratchBuffers(int param_1) {
    NNSi_FndFreeFromDefaultHeap(*(void **)(param_1 + 0x208c));
    NNSi_FndFreeFromDefaultHeap(*(void **)(param_1 + 0x2088));
    NNSi_FndFreeFromDefaultHeap(*(void **)(param_1 + 0x2084));
    NNSi_FndFreeFromDefaultHeap(*(void **)(param_1 + 0x2080));
    NNSi_FndFreeFromDefaultHeap(*(void **)(param_1 + 0x207c));
}
