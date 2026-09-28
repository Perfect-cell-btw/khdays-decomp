

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndAppendListObject(NNSFndList * list, void * object);
void NNS_FndRemoveListObject(NNSFndList * list, void * object);
extern NNSFndList data_0204a314;
extern NNSFndList data_0204a308;

/* ShutdownPlayer -- NitroSystem player.c: ShutdownPlayer. */
void ShutdownPlayer (NNSSndSeqPlayer * seqPlayer)
{
    NNSSndPlayer * player;

    if (seqPlayer->handle != NULL) {
        seqPlayer->handle->player = NULL;
        seqPlayer->handle = NULL;
    }

    player = seqPlayer->player;
    NNS_FndRemoveListObject(&player->playerList, seqPlayer);
    seqPlayer->player = NULL;

    if (seqPlayer->heap != NULL) {
        NNS_FndAppendListObject(&player->heapList, seqPlayer->heap);
        seqPlayer->heap->player = NULL;
        seqPlayer->heap = NULL;
    }

    NNS_FndRemoveListObject(&data_0204a314, seqPlayer);
    NNS_FndAppendListObject(&data_0204a308, seqPlayer);

    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_STOP;
}
