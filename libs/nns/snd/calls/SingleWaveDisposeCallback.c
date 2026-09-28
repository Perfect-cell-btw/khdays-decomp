

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_InvalidateWaveData(const void *start, const void *end);
void SND_SetWaveDataAddress(struct SNDWaveArc * waveArc, int index, const SNDWaveData * address);
const SNDWaveData * SND_GetWaveDataAddress(const struct SNDWaveArc * waveArc, int index);

/* SingleWaveDisposeCallback -- NitroSystem sndarc_loader.c: SingleWaveDisposeCallback. */
void SingleWaveDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    SNDWaveArc * waveArc = (SNDWaveArc *)data1;
    u32 waveNo = data2;

    if (mem == SND_GetWaveDataAddress(waveArc, (int)waveNo)) {
        SND_SetWaveDataAddress(waveArc, (int)waveNo, NULL);
    }

    SND_InvalidateWaveData(mem, (u8 *)mem + size);
}
