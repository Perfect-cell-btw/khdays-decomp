

/* NNSi_SndFaderGet -- NitroSystem fader.c: NNSi_SndFaderGet. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

int NNSi_SndFaderGet (const NNSSndFader * fader)
{
    s64 value;

    if (fader->counter >= fader->frame) {
        return fader->target;
    }

    value = (fader->target - fader->origin)
            * fader->counter / fader->frame
            + fader->origin;

    return (int)value;
}
