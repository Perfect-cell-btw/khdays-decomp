

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArc * data_0204ad4c = 0;   /* sCurrent */

/* NNS_SndArcSetFileAddress -- NitroSystem sndarc.c: NNS_SndArcSetFileAddress. */
void NNS_SndArcSetFileAddress (u32 fileId, void * address)
{
    NNSSndArc * arc = data_0204ad4c;

    arc->fat->files[ fileId ].mem = address;
}
