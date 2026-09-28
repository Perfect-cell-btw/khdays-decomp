

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_InvalidateWaveData(const void *start, const void *end);
void SND_DestroyWaveArc(struct SNDWaveArc * waveArc);
extern void DisposeCallback(void * mem, NNSSndArc * arc, u32 fileId);
extern void DisposeCallback (void * mem, NNSSndArc * arc, u32 fileId);

/* WaveArcDisposeCallback -- NitroSystem sndarc_loader.c: WaveArcDisposeCallback. */
void WaveArcDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    SNDWaveArc * waveArc = (SNDWaveArc *)mem;
    NNSSndArc * arc = (NNSSndArc *)data1;
    u32 fileId = data2;

    DisposeCallback(mem, arc, fileId);
    SND_InvalidateWaveData(mem, (u8 *)mem + size);

    SND_DestroyWaveArc(waveArc);
}
