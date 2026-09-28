

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);
extern BOOL NewSection(NNSSndHeap * heap);
extern BOOL NewSection (NNSSndHeap * heap);

/* NNS_SndHeapSaveState -- NitroSystem heap.c: NNS_SndHeapSaveState. */
int NNS_SndHeapSaveState (NNSSndHeapHandle heap)
{
    BOOL result;

    if (!NNS_FndRecordStateForFrmHeap(heap->handle, heap->sectionList.numObjects)) {
        return -1;
    }

    if (!NewSection(heap)) {
        result = NNS_FndFreeByStateToFrmHeap(heap->handle, 0);
        return -1;
    }

    return heap->sectionList.numObjects - 1;
}
