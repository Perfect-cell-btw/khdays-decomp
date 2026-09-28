/* Teardown: run Ov025_SweepElements, then free the +0x14/+0x10/+0xc sub-allocations if present. */

extern void Ov025_SweepElements();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_ReleaseThreeBuffers(int *arg0) {
    Ov025_SweepElements(arg0);
    if (arg0[5] != 0) NNSi_FndFreeFromDefaultHeap(arg0[5]);
    if (arg0[4] != 0) NNSi_FndFreeFromDefaultHeap(arg0[4]);
    if (arg0[3] != 0) NNSi_FndFreeFromDefaultHeap(arg0[3]);
}
