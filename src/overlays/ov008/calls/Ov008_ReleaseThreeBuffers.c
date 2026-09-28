/* Teardown: run Ov008_SweepElements, then free the +0x14/+0x10/+0xc sub-allocations if present. */

extern void Ov008_SweepElements(void *);
extern void NNSi_FndFreeFromDefaultHeap(void *);
void Ov008_ReleaseThreeBuffers(char *obj)
{
    Ov008_SweepElements(obj);
    if (*(void **)(obj + 0x14) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(obj + 0x14));
    }
    if (*(void **)(obj + 0x10) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(obj + 0x10));
    }
    if (*(void **)(obj + 0xc) != 0) {
        NNSi_FndFreeFromDefaultHeap(*(void **)(obj + 0xc));
    }
}
