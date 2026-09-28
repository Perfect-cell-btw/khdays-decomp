

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nnsys/snd.h"

#define RESERVED_AREASIZE 32

void DC_StoreRange(const void * startAddr, u32 nBytes);
void * NNS_SndHeapAlloc(NNSSndHeapHandle heap, u32 size, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2);
s32 NNS_SndArcReadFile(u32 fileId, void * buffer, s32 size, s32 offset);
u32 NNS_SndArcGetFileSize(u32 fileId);

/* NNSi_SndArcLoadFile -- NitroSystem sndarc_loader.c: NNSi_SndArcLoadFile. */
void * NNSi_SndArcLoadFile (u32 fileId, NNSSndHeapDisposeCallback callback, u32 data1, u32 data2, NNSSndHeapHandle heap)
{
    void * buffer;
    u32 len;

    len = NNS_SndArcGetFileSize(fileId);
    if (len == 0) return NULL;

    if (heap == NNS_SND_HEAP_INVALID_HANDLE) return NULL;

    buffer = NNS_SndHeapAlloc(heap, len + RESERVED_AREASIZE, callback, data1, data2);
    if (buffer == NULL) return NULL;

    if (NNS_SndArcReadFile(fileId, buffer, (s32)len, 0) != len) {
        return NULL;
    }

    DC_StoreRange(buffer, len);

    return buffer;
}
