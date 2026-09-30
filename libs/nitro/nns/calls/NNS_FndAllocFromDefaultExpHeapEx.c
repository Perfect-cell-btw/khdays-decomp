extern void *NNS_FndAllocFromExpHeapEx(void *heap, unsigned int size, int align);

extern void **gCurrentHeap;

void *NNS_FndAllocFromDefaultExpHeapEx(unsigned int size, int align)
{
    return NNS_FndAllocFromExpHeapEx(*gCurrentHeap, size, align);
}
