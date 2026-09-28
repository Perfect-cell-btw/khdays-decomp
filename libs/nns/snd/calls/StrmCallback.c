

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

extern NNSSndStrmChannel data_0204ac30[ 16 ];
extern void * data_0204abf0[ NNS_SND_STRM_CHANNEL_MAX ];   /* buffer, the function's static */

/* StrmCallback -- NitroSystem stream.c: StrmCallback. */
void StrmCallback (NNSSndStrm * stream, NNSSndStrmCallbackStatus status)
{
    const unsigned long blockSize = stream->chBufLen / stream->interval;
    const unsigned long offset = blockSize * stream->curBuffer;
    int index;
    int chNo;

    for (index = 0; index < stream->numChannels; index++) {
        chNo = stream->channelNo[index];

        data_0204abf0[index] = (u8 *)(data_0204ac30[chNo].buffer) + offset;
    }

    stream->callback(
        status,
        stream->numChannels,
        data_0204abf0,
        blockSize,
        stream->format,
        stream->callbackArg
        );

    stream->curBuffer++;
    if (stream->curBuffer >= stream->interval) stream->curBuffer = 0;
}
