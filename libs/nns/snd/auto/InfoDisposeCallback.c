

/* InfoDisposeCallback -- NitroSystem sndarc.c: InfoDisposeCallback. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void InfoDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    NNSSndArc * arc = (NNSSndArc *)data1;

    (void)mem;
    (void)size;
    (void)data2;

    arc->info = NULL;
}
