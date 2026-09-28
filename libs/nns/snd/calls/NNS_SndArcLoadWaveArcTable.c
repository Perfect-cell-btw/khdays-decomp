

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

void * NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2, NNSSndHeapHandle heap);
NNSSndArc * func_0201b3d8(void);
void * NNS_SndArcGetFileAddress(u32 fileId);
void NNS_SndArcSetFileAddress(u32 fileId, void * address);
extern s32 NNS_SndArcReadFile(u32 fileId, void *buffer, s32 size, s32 offset);
extern void *NNS_SndHeapAlloc(NNSSndHeapHandle heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2);
extern void WaveArcTableDisposeCallback(void * mem, u32 size, u32 data1, u32 data2);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void DC_StoreRange(const void *startAddr, u32 nBytes);
/* The header read buffer is the function's own static: only a function-scope static gives the
 * ROM's two pool words for it (its address for the read, its value for waveCount); the module's
 * delinked bss keeps the symbol (tools/share_bss.py promotes the local `name$N` to the global). */
/* khdays: shared-bss */

/* NNS_SndArcLoadWaveArcTable -- NitroSystem sndarc_loader.c: LoadWaveArcTable. */
SNDWaveArc * NNS_SndArcLoadWaveArcTable (u32 fileId, NNSSndHeapHandle heap, BOOL bSetAddr)
{
    static SNDWaveArc data_0204ad50;   /* sWaveArc */
    u32 fileSize;
    SNDWaveArc * waveArc;
    u32 waveCount;
    u32 tableSize;
    s32 result;

    waveArc = (SNDWaveArc *)NNS_SndArcGetFileAddress(fileId);
    if (waveArc == NULL) {
        if (NNS_SndArcReadFile(fileId, &data_0204ad50, 0x3c, 0) != 0x3c) {
            return NULL;
        }
        waveCount = data_0204ad50.waveCount;
        tableSize = waveCount * sizeof(u32);
        fileSize = tableSize * 2;
        if (heap == NULL) {
            return NULL;
        }
        waveArc = (SNDWaveArc *)NNS_SndHeapAlloc(heap, fileSize + 0x5c, WaveArcTableDisposeCallback,
                                              bSetAddr ? (u32)func_0201b3d8() : 0, fileId);
        if (waveArc == NULL) {
            return NULL;
        }
        result = NNS_SndArcReadFile(fileId, waveArc, (s32)(tableSize + 0x3c), 0);
        if (result != tableSize + 0x3c) {
            return NULL;
        }
        MI_CpuCopy8(waveArc->waveOffset, &waveArc->waveOffset[waveArc->waveCount], tableSize);
        MI_CpuFill8(waveArc->waveOffset, 0, tableSize);
        DC_StoreRange(waveArc, fileSize + 0x3c);
        if (bSetAddr) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}
