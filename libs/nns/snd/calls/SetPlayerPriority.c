

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNS_FndRemoveListObject(NNSFndList * list, void * object);
extern NNSFndList data_0204a314;
extern void InsertPlayerList(NNSSndPlayer * player, NNSSndSeqPlayer * seqPlayer);
extern void InsertPrioList(NNSSndSeqPlayer * seqPlayer);
extern void InsertPlayerList (NNSSndPlayer * player, NNSSndSeqPlayer * seqPlayer);
extern void InsertPrioList (NNSSndSeqPlayer * seqPlayer);

/* SetPlayerPriority -- NitroSystem player.c: SetPlayerPriority. */
void SetPlayerPriority (NNSSndSeqPlayer * seqPlayer, int priority)
{
    NNSSndPlayer * player;

    player = seqPlayer->player;

    if (player != NULL) {
        NNS_FndRemoveListObject(&player->playerList, seqPlayer);
        seqPlayer->player = NULL;
    }

    NNS_FndRemoveListObject(&data_0204a314, seqPlayer);

    seqPlayer->prio = (u8)priority;

    if (player != NULL) {
        InsertPlayerList(player, seqPlayer);
    }

    InsertPrioList(seqPlayer);
}
