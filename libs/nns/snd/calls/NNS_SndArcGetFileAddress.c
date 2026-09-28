

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArc * data_0204ad4c = 0;   /* sCurrent */

/* NNS_SndArcGetFileAddress -- NitroSystem sndarc.c: NNS_SndArcGetFileAddress. */
void * NNS_SndArcGetFileAddress (u32 fileId)
{
    NNSSndArc * arc = data_0204ad4c;

    if (fileId >= arc->fat->count) return NULL;
    return arc->fat->files[ fileId ].mem;
}
