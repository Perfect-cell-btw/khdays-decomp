

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndInitList(NNSFndList * list, u16 offset);
extern BOOL NewSection(NNSSndHeap * heap);
extern BOOL NewSection (NNSSndHeap * heap);

/* InitHeap -- NitroSystem heap.c: InitHeap. */
BOOL InitHeap (NNSSndHeap * heap, NNSFndHeapHandle handle)
{
    NNS_FND_INIT_LIST(&heap->sectionList, NNSSndHeapSection, link);
    heap->handle = handle;

    if (!NewSection(heap)) {
        return FALSE;
    }

    return TRUE;
}
