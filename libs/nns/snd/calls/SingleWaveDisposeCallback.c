#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef struct SNDWaveParam {
        u8 format;
        u8 loopflag;
        u16 rate;
        u16 timer;
        u16 loopstart;
        u32 looplen;
    } SNDWaveParam;
void SND_InvalidateWaveData(const void *start, const void *end);
typedef struct SNDBinaryFileHeader {
    char signature[4];
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} SNDBinaryFileHeader;
typedef struct SNDBinaryBlockHeader {
    u32 kind;
    u32 size;
} SNDBinaryBlockHeader;
struct SNDWaveArc;
typedef struct SNDWaveArcLink {
    struct SNDWaveArc * waveArc;
    struct SNDWaveArcLink * next;
} SNDWaveArcLink;
typedef struct SNDWaveArc {
    struct SNDBinaryFileHeader fileHeader;
    struct SNDBinaryBlockHeader blockHeader;
    struct SNDWaveArcLink * topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 waveOffset[0];
} SNDWaveArc;
typedef struct SNDWaveData {
    struct SNDWaveParam param;
    u8 samples[0];
} SNDWaveData;
void SND_SetWaveDataAddress(struct SNDWaveArc * waveArc, int index, const SNDWaveData * address);
const SNDWaveData * SND_GetWaveDataAddress(const struct SNDWaveArc * waveArc, int index);
typedef void (*NNSSndHeapDisposeCallback)(void * mem, u32 size, u32 data1, u32 data2);
struct SNDWaveArc;

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
