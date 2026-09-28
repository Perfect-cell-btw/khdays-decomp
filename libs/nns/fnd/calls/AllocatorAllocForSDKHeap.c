

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"

extern void * OS_AllocFromHeap(OSArenaId id, OSHeapHandle heap, u32 size);

/* AllocatorAllocForSDKHeap -- NitroSystem allocator.c: AllocatorAllocForSDKHeap. */
void * AllocatorAllocForSDKHeap (NNSFndAllocator * pAllocator, u32 size)
{
    OSHeapHandle const heap = (int)pAllocator->pHeap;
    OSArenaId const id = (OSArenaId)pAllocator->heapParam1;
    return OS_AllocFromHeap(id, heap, size);
}
