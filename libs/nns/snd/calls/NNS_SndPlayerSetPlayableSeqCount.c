

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

extern NNSSndPlayer data_0204a760[ 32 ];

/* NNS_SndPlayerSetPlayableSeqCount -- NitroSystem player.c: NNS_SndPlayerSetPlayableSeqCount. */
void NNS_SndPlayerSetPlayableSeqCount (int playerNo, int seqCount)
{

    data_0204a760[ playerNo ].playableSeqCount = (u16)seqCount;
}
