

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define HEAP_ALIGN 32
#define ROUNDUP(value, align) (((u32)(value) + ((align) - 1)) & ~((align) - 1))

void NNS_FndAppendListObject(NNSFndList * list, void * object);
void * NNS_FndGetPrevListObject(NNSFndList * list, void * object);
void * NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);

/* NNS_SndHeapAlloc -- NitroSystem heap.c: NNS_SndHeapAlloc. */
void * NNS_SndHeapAlloc (NNSSndHeapHandle heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2)
{
    NNSSndHeapSection * section;
    NNSSndHeapBlock * block;

    block = (NNSSndHeapBlock *)NNS_FndAllocFromFrmHeapEx(
        heap->handle, sizeof(NNSSndHeapBlock) + ROUNDUP(size, HEAP_ALIGN), HEAP_ALIGN);
    if (block == NULL) return NULL;

    section = (NNSSndHeapSection *)NNS_FndGetPrevListObject(&heap->sectionList, NULL);

    block->size = size;
    block->callback = callback;
    block->data1 = data1;
    block->data2 = data2;
    NNS_FndAppendListObject(&section->blockList, block);

    return block->buffer;
}
