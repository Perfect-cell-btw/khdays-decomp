

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndInsertListObject(NNSFndList * list, void * target, void * object);
void * NNS_FndGetNextListObject(NNSFndList * list, void * object);

/* InsertPlayerList -- NitroSystem player.c: InsertPlayerList. */
void InsertPlayerList (NNSSndPlayer * player, NNSSndSeqPlayer * seqPlayer)
{
    NNSSndSeqPlayer * next = NULL;
    while ((next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&player->playerList, next)) != NULL) {
        if (seqPlayer->prio < next->prio) break;
    }

    NNS_FndInsertListObject(&player->playerList, next, seqPlayer);

    seqPlayer->player = player;
}
