

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndAppendListObject(NNSFndList * list, void * object);
void * NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
extern void NNS_FndInitListWithOffset0(NNSSndHeapSection * section);
extern void NNS_FndInitListWithOffset0 (NNSSndHeapSection * section);

/* NewSection -- NitroSystem heap.c: NewSection. */
BOOL NewSection (NNSSndHeap * heap)
{
    NNSSndHeapSection * section;

    section = (NNSSndHeapSection *)NNS_FndAllocFromFrmHeap(heap->handle, sizeof(NNSSndHeapSection));
    if (section == NULL) {
        return FALSE;
    }
    NNS_FndInitListWithOffset0(section);

    NNS_FndAppendListObject(&heap->sectionList, section);

    return TRUE;
}
