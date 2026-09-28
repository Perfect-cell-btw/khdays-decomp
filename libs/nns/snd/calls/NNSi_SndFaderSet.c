#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef struct NNSSndFader {
    int origin;
    int target;
    int counter;
    int frame;
} NNSSndFader;
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
