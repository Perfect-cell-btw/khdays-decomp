

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

extern NNSSndPlayer data_0204a760[ 32 ];

/* NNS_SndPlayerCountPlayingSeqByPlayerNo -- NitroSystem player.c: NNS_SndPlayerCountPlayingSeqByPlayerNo. */
int NNS_SndPlayerCountPlayingSeqByPlayerNo (int playerNo)
{
    return data_0204a760[playerNo].playerList.numObjects;
}
