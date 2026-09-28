

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void NNS_SndUnlockChannel(u32 chBitFlag);

/* NNS_SndStrmFreeChannel -- NitroSystem stream.c: NNS_SndStrmFreeChannel. */
void NNS_SndStrmFreeChannel (NNSSndStrm * stream)
{

    if (stream->chBitMask == 0) return;

    NNS_SndUnlockChannel(stream->chBitMask);

    stream->chBitMask = 0;
    stream->numChannels = 0;
}
