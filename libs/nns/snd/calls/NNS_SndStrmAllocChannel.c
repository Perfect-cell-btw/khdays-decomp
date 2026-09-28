

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

BOOL NNS_SndLockChannel(u32 chBitFlag);

/* NNS_SndStrmAllocChannel -- NitroSystem stream.c: NNS_SndStrmAllocChannel. */
BOOL NNS_SndStrmAllocChannel (NNSSndStrm * stream, int numChannels, const u8 chNoList[])
{
    u32 chBitMask;
    int i;

    chBitMask = 0;
    for (i = 0; i < numChannels; i++) {

        stream->channelNo[ i ] = chNoList[ i ];
        chBitMask |= (1 << chNoList[ i ]);
    }

    if (!NNS_SndLockChannel(chBitMask)) {
        return FALSE;
    }

    stream->numChannels = numChannels;
    stream->chBitMask = chBitMask;

    return TRUE;
}
