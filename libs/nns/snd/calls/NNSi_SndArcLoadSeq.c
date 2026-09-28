

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

NNSSndArcLoadResult NNSi_SndArcLoadBank(int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);
const NNSSndArcSeqInfo * NNS_SndArcGetSeqInfo(int seqNo);
void * NNS_SndArcGetFileAddress(u32 fileId);
extern NNSSndSeqData * LoadSeq(u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern NNSSndArcLoadResult NNSi_SndArcLoadBank (int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData);
extern NNSSndSeqData * LoadSeq (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);

/* NNSi_SndArcLoadSeq -- NitroSystem sndarc_loader.c: NNSi_SndArcLoadSeq. */
NNSSndArcLoadResult NNSi_SndArcLoadSeq (int seqNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct NNSSndSeqData ** pData)
{
    const NNSSndArcSeqInfo * seqInfo;
    NNSSndSeqData * seqData = NULL;
    SNDBankData * bank = NULL;
    NNSSndArcLoadResult result;

    seqInfo = NNS_SndArcGetSeqInfo(seqNo);
    if (seqInfo == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO;

    result = NNSi_SndArcLoadBank(seqInfo->param.bankNo, loadFlag, heap, bSetAddr, NULL);
    if (result != NNS_SND_ARC_LOAD_SUCESS) return result;

    if (loadFlag & NNS_SND_ARC_LOAD_SEQ) {
        seqData = LoadSeq(seqInfo->fileId, heap, bSetAddr);
        if (seqData == NULL) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ;
        }
    } else {
        seqData = (NNSSndSeqData *)NNS_SndArcGetFileAddress(seqInfo->fileId);
    }

    if (pData != NULL) *pData = seqData;

    return NNS_SND_ARC_LOAD_SUCESS;
}
