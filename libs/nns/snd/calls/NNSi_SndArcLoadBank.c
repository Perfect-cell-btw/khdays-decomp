

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_AssignWaveArc(struct SNDBankData * bank, int index, struct SNDWaveArc * waveArc);
NNSSndArcLoadResult NNSi_SndArcLoadWaveArc(int waveArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDWaveArc ** pData);
const NNSSndArcBankInfo * NNS_SndArcGetBankInfo(int bankNo);
const NNSSndArcWaveArcInfo * NNS_SndArcGetWaveArcInfo(int waveArcNo);
void * NNS_SndArcGetFileAddress(u32 fileId);
extern SNDBankData * LoadBank(u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern BOOL LoadSingleWaves(SNDWaveArc * waveArc, const SNDBankData * bank, int waveArcNo, u32 fileId, NNSSndHeapHandle heap);
extern NNSSndArcLoadResult NNSi_SndArcLoadWaveArc (int waveArcNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDWaveArc ** pData);
extern SNDBankData * LoadBank (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr);
extern BOOL LoadSingleWaves (SNDWaveArc * waveArc, const SNDBankData * bank, int waveArcNo, u32 fileId, NNSSndHeapHandle heap);

/* NNSi_SndArcLoadBank -- NitroSystem sndarc_loader.c: NNSi_SndArcLoadBank. */
NNSSndArcLoadResult NNSi_SndArcLoadBank (int bankNo, u32 loadFlag, NNSSndHeapHandle heap, BOOL bSetAddr, struct SNDBankData ** pData)
{
    const NNSSndArcBankInfo * bankInfo;
    const NNSSndArcWaveArcInfo * waveArcInfo;
    SNDBankData * bank = NULL;
    SNDWaveArc * waveArc;
    NNSSndArcLoadResult result;
    int i;

    bankInfo = NNS_SndArcGetBankInfo(bankNo);
    if (bankInfo == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO;

    if (loadFlag & NNS_SND_ARC_LOAD_BANK) {
        bank = LoadBank(bankInfo->fileId, heap, bSetAddr);
        if (bank == NULL) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK;
        }
    } else {
        bank = (SNDBankData *)NNS_SndArcGetFileAddress(bankInfo->fileId);
    }

    for (i = 0; i < NNS_SND_ARC_BANK_TO_WAVEARC_NUM; i++) {
        if (bankInfo->waveArcNo[i] == NNS_SND_ARC_INVALID_WAVEARC_NO) continue;

        waveArcInfo = NNS_SndArcGetWaveArcInfo(bankInfo->waveArcNo[i]);
        if (waveArcInfo == NULL) return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;

        result = NNSi_SndArcLoadWaveArc(bankInfo->waveArcNo[i], loadFlag, heap, bSetAddr, &waveArc);
        if (result != NNS_SND_ARC_LOAD_SUCESS) return result;

        if (waveArcInfo->flags & NNS_SND_ARC_WAVEARC_SINGLE_LOAD) {

            if (loadFlag & NNS_SND_ARC_LOAD_WAVE) {
                if (!LoadSingleWaves(waveArc, bank, i, waveArcInfo->fileId, heap)) {
                    return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
                }
            }
        }

        if (bank != NULL && waveArc != NULL) {
            SND_AssignWaveArc(bank, i, waveArc);
        }
    }

    if (pData != NULL) *pData = bank;

    return NNS_SND_ARC_LOAD_SUCESS;
}
