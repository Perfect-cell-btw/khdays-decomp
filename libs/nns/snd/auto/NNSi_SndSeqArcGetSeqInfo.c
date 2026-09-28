

/* NNSi_SndSeqArcGetSeqInfo -- NitroSystem seqdata.c: NNSi_SndSeqArcGetSeqInfo. */

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

const NNSSndSeqArcSeqInfo * NNSi_SndSeqArcGetSeqInfo (const NNSSndSeqArc * seqArc, int index)
{

    if (index < 0) return NULL;
    if (index >= seqArc->count) return NULL;
    if (seqArc->info[ index ].offset == NNS_SND_SEQ_ARC_INVALID_OFFSET) return NULL;

    return &seqArc->info[ index ];
}
