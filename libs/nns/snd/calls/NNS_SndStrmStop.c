

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/pxi.h"
#include "nnsys/snd.h"

extern void ForceStopStrm(NNSSndStrm * stream);
extern void ForceStopStrm (NNSSndStrm * stream);

/* NNS_SndStrmStop -- NitroSystem stream.c: NNS_SndStrmStop. */
void NNS_SndStrmStop (NNSSndStrm * stream)
{

    if (!stream->activeFlag) return;

    ForceStopStrm(stream);
}
