

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void * NNS_FndAllocFromUnitHeap(NNSFndHeapHandle heap);

/* AllocatorAllocForUnitHeap -- NitroSystem allocator.c: AllocatorAllocForUnitHeap. */
void * AllocatorAllocForUnitHeap (NNSFndAllocator * pAllocator, u32 size)
{
    NNSFndHeapHandle const heap = pAllocator->pHeap;

    if (size > NNS_FndGetMemBlockSizeForUnitHeap(heap)) {
        return NULL;
    }

    return NNS_FndAllocFromUnitHeap(heap);
}
