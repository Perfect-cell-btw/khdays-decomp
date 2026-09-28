/* Teardown: run Ov006_SweepElements, then free the +0x14/+0x10/+0xc sub-allocations if present. */
extern void Ov006_SweepElements(int);
extern void NNSi_FndFreeFromDefaultHeap(void *);
void Ov006_ReleaseThreeBuffers(int param_1) {
    void *p;
    Ov006_SweepElements(param_1);
    p = *(void **)(param_1 + 0x14); if (p != 0) NNSi_FndFreeFromDefaultHeap(p);
    p = *(void **)(param_1 + 0x10); if (p != 0) NNSi_FndFreeFromDefaultHeap(p);
    p = *(void **)(param_1 + 0xc); if (p != 0) NNSi_FndFreeFromDefaultHeap(p);
}
