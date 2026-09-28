extern int NNSi_FndGetAllocatorForDefaultHeap();
extern int NNS_FndFreeToAllocator();

void CamAnim_FreePlayer(void *ptr) {
    NNS_FndFreeToAllocator(NNSi_FndGetAllocatorForDefaultHeap(0), ptr);
}
