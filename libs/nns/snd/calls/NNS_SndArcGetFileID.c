

/* khdays: shared-bss */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArc * data_0204ad4c = 0;   /* sCurrent */

/* NNS_SndArcGetFileID -- NitroSystem sndarc.c: NNS_SndArcGetFileID. */
FSFileID NNS_SndArcGetFileID (void)
{
    NNSSndArc * arc = data_0204ad4c;

    return arc->fileId;
}
