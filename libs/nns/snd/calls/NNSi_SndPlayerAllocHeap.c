

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
void NNS_SndHeapClear(NNSSndHeapHandle heap);
extern NNSSndPlayer data_0204a760[ 32 ];

/* NNSi_SndPlayerAllocHeap -- NitroSystem player.c: NNSi_SndPlayerAllocHeap. */
NNSSndHeapHandle NNSi_SndPlayerAllocHeap (int playerNo, NNSSndSeqPlayer * seqPlayer)
{
    NNSSndPlayer * player;
    NNSSndPlayerHeap * heap;

    player = &data_0204a760[ playerNo ];

    heap = (NNSSndPlayerHeap *)NNS_FndGetNextListObject(&player->heapList, NULL);
    if (heap == NULL) return NULL;

    NNS_FndRemoveListObject(&player->heapList, heap);

    heap->player = seqPlayer;
    seqPlayer->heap = heap;

    NNS_SndHeapClear(heap->handle);

    return heap->handle;
}
