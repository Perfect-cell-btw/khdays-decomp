/* Allocates the 0x20-byte animation player from the default heap allocator. */

extern int NNSi_FndGetAllocatorForDefaultHeap();
extern int NNS_FndAllocFromAllocator();

void CamAnim_AllocPlayer(void) {
    NNS_FndAllocFromAllocator(NNSi_FndGetAllocatorForDefaultHeap(0), 0x20);
}
