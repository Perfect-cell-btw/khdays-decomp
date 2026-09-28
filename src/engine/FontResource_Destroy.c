/* Frees a font resource's data and returns the free size of the default heap. */

extern void NNSi_FndFreeFromDefaultHeap(void *);
extern int NNS_FndGetAllocatableSizeForExpHeapEx(void *, int);
extern void **data_0204c02c;

int FontResource_Destroy(void *p) {
    NNSi_FndFreeFromDefaultHeap(*(void **)((char *)p + 8));
    return NNS_FndGetAllocatableSizeForExpHeapEx(*data_0204c02c, 4);
}
