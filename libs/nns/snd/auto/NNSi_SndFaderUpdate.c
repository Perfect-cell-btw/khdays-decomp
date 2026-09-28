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

/* NNSi_SndFaderUpdate -- NitroSystem fader.c: NNSi_SndFaderUpdate. */
void NNSi_SndFaderUpdate (NNSSndFader * fader)
{

    if (fader->counter < fader->frame) {
        fader->counter++;
    }
}
