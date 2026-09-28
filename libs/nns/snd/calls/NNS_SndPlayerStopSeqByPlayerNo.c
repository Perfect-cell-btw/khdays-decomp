

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer * seqPlayer, int fadeFrame);
extern NNSSndSeqPlayer data_0204a320[ 16 ];
extern NNSSndPlayer data_0204a760[ 32 ];
extern void NNSi_SndPlayerStopSeq (NNSSndSeqPlayer * seqPlayer, int fadeFrame);

/* NNS_SndPlayerStopSeqByPlayerNo -- NitroSystem player.c: NNS_SndPlayerStopSeqByPlayerNo. */
void NNS_SndPlayerStopSeqByPlayerNo (int playerNo, int fadeFrame)
{
    NNSSndSeqPlayer * seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_NUM; i++) {
        seqPlayer = &data_0204a320[ i ];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP &&
            seqPlayer->player == &data_0204a760[ playerNo ]) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}
