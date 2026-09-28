

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define NNS_FROM_TOOL 

/* FatDisposeCallback -- NitroSystem sndarc.c: FatDisposeCallback. */
void FatDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    NNSSndArc * arc = (NNSSndArc *)data1;
    int i;

    (void)mem;
    (void)size;
    (void)data2;

    for (i = 0; i < arc->fat->count; i++) {
#ifndef NNS_FROM_TOOL
#endif
    }

    arc->fat = NULL;
}
