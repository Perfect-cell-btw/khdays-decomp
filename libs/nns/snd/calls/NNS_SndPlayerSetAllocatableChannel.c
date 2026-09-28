

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

extern NNSSndPlayer data_0204a760[ 32 ];

/* NNS_SndPlayerSetAllocatableChannel -- NitroSystem player.c: NNS_SndPlayerSetAllocatableChannel. */
void NNS_SndPlayerSetAllocatableChannel (int playerNo, u32 chBitFlag)
{

    data_0204a760[ playerNo ].allocChBitFlag = chBitFlag;
}
