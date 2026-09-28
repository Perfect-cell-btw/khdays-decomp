

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer * seqPlayer, int fadeFrame);
extern void NNSi_SndPlayerStopSeq (NNSSndSeqPlayer * seqPlayer, int fadeFrame);

/* NNS_SndPlayerStopSeq -- NitroSystem player.c: NNS_SndPlayerStopSeq. */
void NNS_SndPlayerStopSeq (NNSSndHandle * handle, int fadeFrame)
{
    NNSi_SndPlayerStopSeq(handle->player, fadeFrame);
}
