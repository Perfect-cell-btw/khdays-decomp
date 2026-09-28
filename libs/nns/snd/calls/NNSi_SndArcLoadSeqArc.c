

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

const NNSSndArcSeqArcInfo * NNS_SndArcGetSeqArcInfo(int seqNo);
void * NNS_SndArcGetFileAddress(u32 fileId);
extern NNSSndSeqArc * LoadSeqArc(u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern NNSSndSeqArc * LoadSeqArc (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);

/* NNSi_SndArcLoadSeqArc -- NitroSystem sndarc_loader.c: NNSi_SndArcLoadSeqArc. */
NNSSndArcLoadResult NNSi_SndArcLoadSeqArc (int seqArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqArc ** pData)
{
    const NNSSndArcSeqArcInfo * seqArcInfo;
    NNSSndSeqArc * seqArc = NULL;

    seqArcInfo = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (seqArcInfo == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO;

    if (loadFlag & NNS_SND_ARC_LOAD_SEQARC) {
        seqArc = LoadSeqArc(seqArcInfo->fileId, heap, bSetAddr);
        if (seqArc == NULL) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC;
        }
    } else {
        seqArc = (NNSSndSeqArc *)NNS_SndArcGetFileAddress(seqArcInfo->fileId);
    }

    if (pData != NULL) *pData = seqArc;

    return NNS_SND_ARC_LOAD_SUCESS;
}
