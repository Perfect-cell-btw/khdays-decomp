#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define NNS_FND_FRMHEAP_FREE_HEAD (1 << 0)
#define NNS_FND_FRMHEAP_FREE_TAIL (1 << 1)

typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
typedef void * (*MIAllocatorAllocFunction)(void * userdata, u32 length, u32 alignment);
typedef void (*MIAllocatorFreeFunction)(void * userdata, void * buffer);
typedef struct {
    void * prevObject;
    void * nextObject;
} NNSFndLink;
typedef struct {
    void * headObject;
    void * tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;
struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void * heapStart;
    void * heapEnd;
    u32 attribute;
};
typedef NNSiFndHeapHead * NNSFndHeapHandle;
extern void NNS_FndResetFrmHeapHead (NNSiFndHeapHead * pHeapHd);
extern void NNS_FndResetFrmHeapTail (NNSiFndHeapHead * pHeapHd);

/* NNS_FndFreeToFrmHeap -- NitroSystem frameheap.c: NNS_FndFreeToFrmHeap. */
void NNS_FndFreeToFrmHeap (NNSFndHeapHandle heap, int mode)
{

    if (mode & NNS_FND_FRMHEAP_FREE_HEAD) {
        NNS_FndResetFrmHeapHead(heap);
    }

    if (mode & NNS_FND_FRMHEAP_FREE_TAIL) {
        NNS_FndResetFrmHeapTail(heap);
    }
}
