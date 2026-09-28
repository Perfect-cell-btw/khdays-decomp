

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void * NNS_FndGetNextListObject(NNSFndList * list, void * object);
extern NNSFndList data_0204a314;

/* NNS_SndPlayerCountPlayingSeqBySeqNo -- NitroSystem player.c: NNS_SndPlayerCountPlayingSeqBySeqNo. */
int NNS_SndPlayerCountPlayingSeqBySeqNo (int seqNo)
{
    int count = 0;

    NNSSndSeqPlayer * seqPlayer = NULL;
    while ((seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_0204a314, seqPlayer)) != NULL) {
        if (seqPlayer->seqType == NNS_SND_PLAYER_SEQ_TYPE_SEQ &&
            seqPlayer->seqNo == seqNo) {
            count++;
        }
    }

    return count;
}
