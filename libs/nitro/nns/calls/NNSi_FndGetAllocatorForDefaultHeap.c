extern void *gCurrentHeap;

void *NNSi_FndGetAllocatorForDefaultHeap(void *p) {
    if (p == 0) p = gCurrentHeap;
    return (char *)p + 4;
}
