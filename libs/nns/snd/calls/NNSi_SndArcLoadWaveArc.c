

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

const NNSSndArcWaveArcInfo * NNS_SndArcGetWaveArcInfo(int waveArcNo);
void * NNS_SndArcGetFileAddress(u32 fileId);
extern SNDWaveArc * LoadWaveArc(u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern SNDWaveArc * NNS_SndArcLoadWaveArcTable(u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern SNDWaveArc * LoadWaveArc (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern SNDWaveArc * NNS_SndArcLoadWaveArcTable (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);

/* NNSi_SndArcLoadWaveArc -- NitroSystem sndarc_loader.c: NNSi_SndArcLoadWaveArc. */
NNSSndArcLoadResult NNSi_SndArcLoadWaveArc (int waveArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDWaveArc ** pData)
{
    const NNSSndArcWaveArcInfo * waveArcInfo;
    SNDWaveArc * waveArc = NULL;

    waveArcInfo = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (waveArcInfo == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;

    if (loadFlag & NNS_SND_ARC_LOAD_WAVE) {
        if (waveArcInfo->flags & NNS_SND_ARC_WAVEARC_SINGLE_LOAD) {

            waveArc = NNS_SndArcLoadWaveArcTable(waveArcInfo->fileId, heap, bSetAddr);
        } else {

            waveArc = LoadWaveArc(waveArcInfo->fileId, heap, bSetAddr);
        }

        if (waveArc == NULL) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
        }
    } else {
        waveArc = (SNDWaveArc *)NNS_SndArcGetFileAddress(waveArcInfo->fileId);
    }

    if (pData != NULL) *pData = waveArc;

    return NNS_SND_ARC_LOAD_SUCESS;
}
