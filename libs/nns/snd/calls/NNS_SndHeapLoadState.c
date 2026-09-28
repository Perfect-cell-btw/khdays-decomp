

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void * NNS_FndGetPrevListObject(NNSFndList * list, void * object);
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);
void NNS_SndHeapClear(NNSSndHeapHandle heap);
extern BOOL NewSection(NNSSndHeap * heap);
extern void EraseSync(void);
extern void NNS_SndHeapClear (NNSSndHeapHandle heap);
extern BOOL NewSection (NNSSndHeap * heap);
extern void EraseSync (void);

/* NNS_SndHeapLoadState -- NitroSystem heap.c: NNS_SndHeapLoadState. */
void NNS_SndHeapLoadState (NNSSndHeapHandle heap, int level)
{
    NNSSndHeapSection * section;
    void * object = NULL;
    BOOL result;
    BOOL doCallback = FALSE;

    if (level == 0) {
        NNS_SndHeapClear(heap);
        return;
    }

    while (level < heap->sectionList.numObjects) {
        section = (NNSSndHeapSection *)NNS_FndGetPrevListObject(&heap->sectionList, NULL);

        while ((object = NNS_FndGetPrevListObject(&section->blockList, object)) != NULL) {
            NNSSndHeapBlock * block = (NNSSndHeapBlock *)object;
            if (block->callback != NULL) {
                block->callback(block->buffer, block->size, block->data1, block->data2);
                doCallback = TRUE;
            }
        }

        NNS_FndRemoveListObject(&heap->sectionList, section);
    }

    result = NNS_FndFreeByStateToFrmHeap(heap->handle, (u32)level);

    if (doCallback) EraseSync();

    result = NNS_FndRecordStateForFrmHeap(heap->handle, heap->sectionList.numObjects);

    result = NewSection(heap);
}
