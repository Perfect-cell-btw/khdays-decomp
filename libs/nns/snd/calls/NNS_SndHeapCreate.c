

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define NNS_FndCreateFrmHeap(startAddress, size) func_02010b88(startAddress, size, 0)
#define ROUNDUP(value, align) (((u32)(value) + ((align) - 1)) & ~((align) - 1))

NNSFndHeapHandle func_02010b88(void * startAddress, u32 size, int optFlag);
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
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
