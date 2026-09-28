

/* NNSi_SndFaderUpdate -- NitroSystem fader.c: NNSi_SndFaderUpdate. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void NNSi_SndFaderUpdate (NNSSndFader * fader)
{

    if (fader->counter < fader->frame) {
        fader->counter++;
    }
}
