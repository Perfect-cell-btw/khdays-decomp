

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArcLoadResult NNSi_SndArcLoadSeqArc(int seqArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqArc ** pData);
extern NNSSndArcLoadResult NNSi_SndArcLoadSeqArc (int seqArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqArc ** pData);

/* NNS_SndArcLoadSeqArc -- NitroSystem sndarc_loader.c: NNS_SndArcLoadSeqArc. */
BOOL NNS_SndArcLoadSeqArc (int seqArcNo, NNSSndHeapHandle heap)
{
    NNSSndArcLoadResult result;

    result = NNSi_SndArcLoadSeqArc(seqArcNo, NNS_SND_ARC_LOAD_ALL, heap, TRUE, NULL);

    return result == NNS_SND_ARC_LOAD_SUCESS ? TRUE : FALSE;
}
