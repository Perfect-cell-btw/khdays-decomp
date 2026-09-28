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

/* NNSi_SndFaderIsFinished -- NitroSystem fader.c: NNSi_SndFaderIsFinished. */
BOOL NNSi_SndFaderIsFinished (const NNSSndFader * fader)
{

    return fader->counter >= fader->frame ? TRUE : FALSE;
}
