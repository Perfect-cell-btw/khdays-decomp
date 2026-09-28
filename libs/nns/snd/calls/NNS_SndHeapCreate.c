#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define NNS_FndCreateFrmHeap(startAddress, size) func_02010b88(startAddress, size, 0)
#define NNS_FND_HEAP_INVALID_HANDLE NULL
#define NNS_SND_HEAP_INVALID_HANDLE NNS_FND_HEAP_INVALID_HANDLE
#define ROUNDUP(value, align) (((u32)(value) + ((align) - 1)) & ~((align) - 1))

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
typedef void (*NNSFndHeapVisitor)(void * memBlock, NNSFndHeapHandle heap, u32 userParam);
NNSFndHeapHandle func_02010b88(void * startAddress, u32 size, u16 optFlag);
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
struct NNSSndHeap;
typedef void (*NNSSndHeapDisposeCallback)(void * mem, u32 size, u32 data1, u32 data2);
typedef struct NNSSndHeap * NNSSndHeapHandle;
typedef struct NNSSndHeap {
    NNSFndHeapHandle handle;
    NNSFndList sectionList;
} NNSSndHeap;
extern BOOL InitHeap(NNSSndHeap * heap, NNSFndHeapHandle handle);
extern BOOL InitHeap (NNSSndHeap * heap, NNSFndHeapHandle handle);

/* NNS_SndHeapCreate -- NitroSystem heap.c: NNS_SndHeapCreate. */
NNSSndHeapHandle NNS_SndHeapCreate (void * startAddress, u32 size)
{
    NNSSndHeap * heap;
    void * endAddress;
    NNSFndHeapHandle handle;

    endAddress = (u8 *)startAddress + size;
    startAddress = (void *)ROUNDUP(startAddress, 4);

    if (startAddress > endAddress) return NNS_SND_HEAP_INVALID_HANDLE;

    size = (u32)((u8 *)endAddress - (u8 *)startAddress);
    if (size < sizeof(NNSSndHeap)) {
        return NNS_SND_HEAP_INVALID_HANDLE;
    }

    size -= sizeof(NNSSndHeap);

    heap = (NNSSndHeap *)startAddress;
    startAddress = heap + 1;

    handle = NNS_FndCreateFrmHeap(startAddress, size);
    if (handle == NNS_FND_HEAP_INVALID_HANDLE) {
        return NULL;
    }

    if (!InitHeap(heap, handle)) {
        NNS_FndDestroyFrmHeap(handle);
        return NNS_SND_HEAP_INVALID_HANDLE;
    }

    return heap;
}
