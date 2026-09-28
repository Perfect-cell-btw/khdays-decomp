

/* NNSi_SndFaderInit -- NitroSystem fader.c: NNSi_SndFaderInit. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndFaderInit (NNSSndFader * fader)
{

    fader->origin = fader->target = 0;
    fader->counter = fader->frame = 0;
}
