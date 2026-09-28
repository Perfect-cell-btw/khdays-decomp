

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void * NNS_FndGetPrevListObject(NNSFndList * list, void * object);
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode);
extern BOOL NewSection(NNSSndHeap * heap);
extern void EraseSync(void);
extern BOOL NewSection (NNSSndHeap * heap);
extern void EraseSync (void);

/* NNS_SndHeapClear -- NitroSystem heap.c: NNS_SndHeapClear. */
void NNS_SndHeapClear (NNSSndHeapHandle heap)
{
    NNSSndHeapSection * section = NULL;
    void * object;
    BOOL result;
    BOOL doCallback = FALSE;

    while ((section = (NNSSndHeapSection *)NNS_FndGetPrevListObject(&heap->sectionList, NULL)) != NULL) {

        object = NULL;
        while ((object = NNS_FndGetPrevListObject(&section->blockList, object)) != NULL) {
            NNSSndHeapBlock * block = (NNSSndHeapBlock *)object;
            if (block->callback != NULL) {
                block->callback(block->buffer, block->size, block->data1, block->data2);
                doCallback = TRUE;
            }
        }

        NNS_FndRemoveListObject(&heap->sectionList, section);
    }

    NNS_FndFreeToFrmHeap(heap->handle, NNS_FND_FRMHEAP_FREE_ALL);

    if (doCallback) EraseSync();

    result = NewSection(heap);
}
