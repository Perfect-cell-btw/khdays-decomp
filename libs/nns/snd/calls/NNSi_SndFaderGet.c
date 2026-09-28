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

/* NNSi_SndFaderGet -- NitroSystem fader.c: NNSi_SndFaderGet. */
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
