

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void SND_DestroyWaveArc(struct SNDWaveArc * waveArc);
extern void DisposeCallback(void * mem, NNSSndArc * arc, u32 fileId);
extern void DisposeCallback (void * mem, NNSSndArc * arc, u32 fileId);

/* WaveArcTableDisposeCallback -- NitroSystem sndarc_loader.c: WaveArcTableDisposeCallback. */
void WaveArcTableDisposeCallback (void * mem, u32 size, u32 data1, u32 data2)
{
    SNDWaveArc * waveArc = (SNDWaveArc *)mem;
    NNSSndArc * arc = (NNSSndArc *)data1;
    u32 fileId = data2;

    (void)size;

    DisposeCallback(mem, arc, fileId);
    SND_DestroyWaveArc(waveArc);
}
