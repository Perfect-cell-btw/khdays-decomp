

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

u32 SND_GetCurrentCommandTag(void);
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, const struct SNDBankData *bank);
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern void InitPlayer(NNSSndSeqPlayer * seqPlayer);
extern void InitPlayer (NNSSndSeqPlayer * seqPlayer);

/* NNSi_SndPlayerStartSeq -- NitroSystem player.c: NNSi_SndPlayerStartSeq. */
void NNSi_SndPlayerStartSeq (NNSSndSeqPlayer * seqPlayer, const void * seqDataBase, u32 seqDataOffset, const SNDBankData * bank)
{
    NNSSndPlayer * player;

    player = seqPlayer->player;

    SND_PrepareSeq(
        seqPlayer->playerNo,
        seqDataBase,
        seqDataOffset,
        bank
        );
    if (player->allocChBitFlag) {
        SND_SetTrackAllocatableChannel(
            seqPlayer->playerNo,
            0xffff,
            player->allocChBitFlag
            );
    }

    InitPlayer(seqPlayer);
    seqPlayer->commandTag = SND_GetCurrentCommandTag();
    seqPlayer->prepareFlag = TRUE;
    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_PLAY;
}
