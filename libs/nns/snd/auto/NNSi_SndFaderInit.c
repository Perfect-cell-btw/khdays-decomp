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

/* NNSi_SndFaderInit -- NitroSystem fader.c: NNSi_SndFaderInit. */
void NNSi_SndFaderInit (NNSSndFader * fader)
{

    fader->origin = fader->target = 0;
    fader->counter = fader->frame = 0;
}
