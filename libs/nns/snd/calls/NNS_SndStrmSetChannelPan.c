

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

void SND_SetChannelPan(u32 chBitMask, int pan);

/* NNS_SndStrmSetChannelPan -- NitroSystem stream.c: NNS_SndStrmSetChannelPan. */
void NNS_SndStrmSetChannelPan (NNSSndStrm * stream, int chNo, int pan)
{

    if (chNo > stream->numChannels - 1) return;

    SND_SetChannelPan((u32)(1 << stream->channelNo[ chNo ]), pan);
}
