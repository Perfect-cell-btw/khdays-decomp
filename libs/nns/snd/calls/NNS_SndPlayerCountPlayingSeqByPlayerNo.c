#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef struct {
    void * headObject;
    void * tailObject;
    u16 numObjects;
    u16 offset;
} NNSFndList;
typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
struct NNSSndPlayer;
typedef struct NNSSndPlayer {
    NNSFndList playerList;
    NNSFndList heapList;
    u32 playableSeqCount;
    u32 allocChBitFlag;
    u8 volume;
    u8 pad_;
    u16 pad2_;
} NNSSndPlayer;
extern NNSSndPlayer data_0204a760[ 32 ];

/* NNS_SndPlayerCountPlayingSeqByPlayerNo -- NitroSystem player.c: NNS_SndPlayerCountPlayingSeqByPlayerNo. */
int NNS_SndPlayerCountPlayingSeqByPlayerNo (int playerNo)
{
    return data_0204a760[playerNo].playerList.numObjects;
}
