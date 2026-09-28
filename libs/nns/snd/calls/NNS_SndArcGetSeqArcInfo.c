

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

extern const void * GetPtrConst(const void * base, u32 offset);
extern const NNSSndArcOffsetTable * GetOffsetTable(const NNSSndArcInfo * info, u32 offset);
static inline
const void * GetPtrConst (const void * base, u32 offset)
{
    if (offset == 0) return NULL ;
    return (const u8 *)base + offset;
}
static inline
const NNSSndArcOffsetTable * GetOffsetTable (const NNSSndArcInfo * info, u32 offset)
{
    return (const NNSSndArcOffsetTable *)GetPtrConst(info, offset);
}

/* khdays: shared-bss */
NNSSndArc * data_0204ad4c = 0;   /* sCurrent */

/* NNS_SndArcGetSeqArcInfo -- NitroSystem sndarc.c: NNS_SndArcGetSeqArcInfo. */
const NNSSndArcSeqArcInfo * NNS_SndArcGetSeqArcInfo (int seqArcNo)
{
    NNSSndArc * arc = data_0204ad4c;
    const NNSSndArcOffsetTable * table;

    table = GetOffsetTable(arc->info, arc->info->seqArcOffset);
    if (table == NULL) return NULL;

    if (seqArcNo < 0) return NULL;
    if (seqArcNo >= table->count) return NULL;

    return (const NNSSndArcSeqArcInfo *)GetPtrConst(arc->info, table->offset[ seqArcNo ]);
}
