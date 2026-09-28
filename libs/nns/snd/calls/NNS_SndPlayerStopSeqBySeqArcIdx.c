

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer * seqPlayer, int fadeFrame);
extern NNSSndSeqPlayer data_0204a320[ 16 ];
extern void NNSi_SndPlayerStopSeq (NNSSndSeqPlayer * seqPlayer, int fadeFrame);

/* NNS_SndPlayerStopSeqBySeqArcIdx -- NitroSystem player.c: NNS_SndPlayerStopSeqBySeqArcIdx. */
void NNS_SndPlayerStopSeqBySeqArcIdx (int seqArcNo, int index, int fadeFrame)
{
    NNSSndSeqPlayer * seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_NUM; i++) {
        seqPlayer = &data_0204a320[ i ];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP &&
            seqPlayer->seqType == NNS_SND_PLAYER_SEQ_TYPE_SEQARC &&
            seqPlayer->seqNo == seqArcNo &&
            seqPlayer->seqArcIndex == index) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}
