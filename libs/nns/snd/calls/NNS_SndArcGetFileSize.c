

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArc * data_0204ad4c = 0;   /* sCurrent */

/* NNS_SndArcGetFileSize -- NitroSystem sndarc.c: NNS_SndArcGetFileSize. */
u32 NNS_SndArcGetFileSize (u32 fileId)
{
    NNSSndArc * arc = data_0204ad4c;

    if (fileId >= arc->fat->count) return 0;
    return arc->fat->files[ fileId ].size;
}
