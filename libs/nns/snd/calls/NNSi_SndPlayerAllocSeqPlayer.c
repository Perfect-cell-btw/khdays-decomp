

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
inline BOOL NNS_SndHandleIsValid (const struct NNSSndHandle * handle)
{
    return handle->player != NULL ;
}
void NNS_SndHandleReleaseSeq(NNSSndHandle * handle);
extern NNSSndPlayer data_0204a760[ 32 ];
extern void ForceStopSeq(NNSSndSeqPlayer * seqPlayer);
extern NNSSndSeqPlayer * AllocSeqPlayer(int prio);
extern void InsertPlayerList(NNSSndPlayer * player, NNSSndSeqPlayer * seqPlayer);
extern void NNS_SndHandleReleaseSeq (NNSSndHandle * handle);
extern void InsertPlayerList (NNSSndPlayer * player, NNSSndSeqPlayer * seqPlayer);
extern void ForceStopSeq (NNSSndSeqPlayer * seqPlayer);
extern NNSSndSeqPlayer * AllocSeqPlayer (int prio);

/* NNSi_SndPlayerAllocSeqPlayer -- NitroSystem player.c: NNSi_SndPlayerAllocSeqPlayer. */
NNSSndSeqPlayer * NNSi_SndPlayerAllocSeqPlayer (NNSSndHandle * handle, int playerNo, int prio)
{
    NNSSndSeqPlayer * seqPlayer;
    NNSSndPlayer * player;

    player = &data_0204a760[ playerNo ];

    if (NNS_SndHandleIsValid(handle)) {
        NNS_SndHandleReleaseSeq(handle);
    }

    if (player->playerList.numObjects >= player->playableSeqCount) {

        seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&player->playerList, NULL);
        if (seqPlayer == NULL) return NULL;
        if (prio < seqPlayer->prio) return NULL;

        ForceStopSeq(seqPlayer);
    }

    seqPlayer = AllocSeqPlayer(prio);
    if (seqPlayer == NULL) return NULL;

    InsertPlayerList(player, seqPlayer);

    seqPlayer->handle = handle;
    handle->player = seqPlayer;

    return seqPlayer;
}
