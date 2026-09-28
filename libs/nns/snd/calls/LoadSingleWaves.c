

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

struct SNDInstPos SND_GetFirstInstDataPos(const struct SNDBankData * bank);
BOOL SND_GetNextInstData(const struct SNDBankData * bank, struct SNDInstData * inst, struct SNDInstPos * pos);
extern BOOL SndLoadWaveData(SNDWaveArc * waveArc, int waveNo, u32 fileId, NNSSndHeapHandle heap);
extern BOOL SndLoadWaveData (SNDWaveArc * waveArc, int waveNo, u32 fileId, NNSSndHeapHandle heap);

/* LoadSingleWaves -- NitroSystem sndarc_loader.c: LoadSingleWaves. */
BOOL LoadSingleWaves (SNDWaveArc * waveArc, const SNDBankData * bank, int waveArcNo, u32 fileId, NNSSndHeapHandle heap)
{
    SNDInstPos pos = SND_GetFirstInstDataPos(bank);
    SNDInstData inst;

    if (bank == NULL) {
        return FALSE;
    }

    while (SND_GetNextInstData(bank, &inst, &pos)) {
        if (inst.type == SND_INST_PCM && waveArcNo == inst.param.wave[1]) {
            if (!SndLoadWaveData(waveArc, inst.param.wave[0], fileId, heap)) {
                return FALSE;
            }
        }
    }

    return TRUE;
}
