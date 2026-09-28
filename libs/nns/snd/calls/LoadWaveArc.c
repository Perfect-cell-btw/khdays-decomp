

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void * NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2, NNSSndHeapHandle heap);
NNSSndArc * func_0201b3d8(void);
void * NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, void * address);
extern void WaveArcDisposeCallback(void * mem, u32 size, u32 data1, u32 data2);
extern void * NNSi_SndArcLoadFile (u32 fileId, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2, NNSSndHeapHandle heap);
extern void WaveArcDisposeCallback (void * mem, u32 size, u32 data1, u32 data2);

/* LoadWaveArc -- NitroSystem sndarc_loader.c: LoadWaveArc. */
SNDWaveArc * LoadWaveArc (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr)
{
    void * buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == NULL) {
        buffer = NNSi_SndArcLoadFile(
            fileId,
            WaveArcDisposeCallback,
            bSetAddr ? (u32)func_0201b3d8() : 0,
            fileId,
            heap
            );

        if (bSetAddr && buffer != NULL) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }

    return (SNDWaveArc *)buffer;
}
