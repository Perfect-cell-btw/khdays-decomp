#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define NNS_SND_ARC_LOAD_WAVE (1 << 2)
#define NNS_SND_ARC_WAVEARC_SINGLE_LOAD (1 << 0)

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
typedef struct {
    void * prevObject;
    void * nextObject;
} NNSFndLink;
typedef struct {
    void * headObject;
    void * tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;
struct NNSiFndHeapHead {
    u32 signature;
    NNSFndLink link;
    NNSFndList childList;
    void * heapStart;
    void * heapEnd;
    u32 attribute;
};
typedef NNSiFndHeapHead * NNSFndHeapHandle;
typedef void (*NNSFndHeapVisitor)(void * memBlock, NNSFndHeapHandle heap, u32 userParam);
typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
struct NNSSndHeap;
typedef void (*NNSSndHeapDisposeCallback)(void * mem, u32 size, u32 data1, u32 data2);
typedef struct NNSSndHeap * NNSSndHeapHandle;
struct SNDWaveArc;
typedef enum NNSSndArcLoadResult {
    NNS_SND_ARC_LOAD_SUCESS = 0,
    NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE
} NNSSndArcLoadResult;
typedef struct NNSSndArcWaveArcInfo {
    u32 fileId :24;
    u32 flags  :8;
} NNSSndArcWaveArcInfo;
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
