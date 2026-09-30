extern void *NNS_FndAllocFromExpHeapEx(int heap, unsigned size, int align);
extern int *gCurrentHeap;

void *NNSi_FndAllocFromDefaultExpHeap(unsigned size) {
    return NNS_FndAllocFromExpHeapEx(*gCurrentHeap, size, 4);
}
