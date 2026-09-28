

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void NNS_SndHeapDestroy(NNSSndHeapHandle heap);
extern NNSSndPlayer data_0204a760[ 32 ];

/* PlayerHeapDisposeCallback -- NitroSystem player.c: PlayerHeapDisposeCallback. */
void PlayerHeapDisposeCallback (void * mem, u32, u32, u32)
{
    NNSSndPlayerHeap * heap = (NNSSndPlayerHeap *)mem;
    NNSSndSeqPlayer * seqPlayer;

    if (heap->handle == NNS_SND_HEAP_INVALID_HANDLE) return;

    NNS_SndHeapDestroy(heap->handle);

    seqPlayer = heap->player;
    if (seqPlayer != NULL) {
        seqPlayer->heap = NULL;
    } else {
        NNS_FndRemoveListObject(&data_0204a760[ heap->playerNo ].heapList, heap);
    }
}
