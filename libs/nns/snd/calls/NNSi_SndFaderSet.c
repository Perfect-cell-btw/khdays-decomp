

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

int NNSi_SndFaderGet(const NNSSndFader * fader);
extern int NNSi_SndFaderGet (const NNSSndFader * fader);

/* NNSi_SndFaderSet -- NitroSystem fader.c: NNSi_SndFaderSet. */
void NNSi_SndFaderSet (NNSSndFader * fader, int target, int frame)
{

    fader->origin = NNSi_SndFaderGet(fader);
    fader->target = target;
    fader->frame = frame;
    fader->counter = 0;

}
