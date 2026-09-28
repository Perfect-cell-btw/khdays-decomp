

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

extern void StrmCallback(NNSSndStrm * stream, NNSSndStrmCallbackStatus status);
extern void StrmCallback (NNSSndStrm * stream, NNSSndStrmCallbackStatus status);

/* AlarmCallback -- NitroSystem stream.c: AlarmCallback. */
void AlarmCallback (void * arg)
{
    StrmCallback((NNSSndStrm *)arg, NNS_SND_STRM_CALLBACK_INTERVAL);
}
