

/* NNSi_SndFaderIsFinished -- NitroSystem fader.c: NNSi_SndFaderIsFinished. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

BOOL NNSi_SndFaderIsFinished (const NNSSndFader * fader)
{

    return fader->counter >= fader->frame ? TRUE : FALSE;
}
