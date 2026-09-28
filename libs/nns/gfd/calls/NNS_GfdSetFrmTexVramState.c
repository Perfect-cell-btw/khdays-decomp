#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define NNS_GFD_NUM_TEX_VRAM_REGION 5

typedef struct NNSGfdFrmTexVramState {
    u32 address[10];
} NNSGfdFrmTexVramState;
typedef void (*NNSGfdFrmTexVramDebugDumpCallBack)(int index, u32 startAddr, u32 endAddr, u32 blockMax, BOOL bActive, void * pUserContext);
typedef struct NNSGfdFrmTexRegionState {
    u32 head;
    u32 tail;
    BOOL bActive;
    const BOOL bHalfSize;
    const u16 index;
    const u16 pad16_;
    const u32 baseAddress;
} NNSGfdFrmTexRegionState;
extern NNSGfdFrmTexRegionState data_02042418[5 ];

/* NNS_GfdSetFrmTexVramState -- NitroSystem gfd_FrameTexVramMan.c: NNS_GfdSetFrmTexVramState. */
void NNS_GfdSetFrmTexVramState (const NNSGfdFrmTexVramState * pState)
{
    int i;

    for (i = 0; i < NNS_GFD_NUM_TEX_VRAM_REGION; i++)
    {
        data_02042418[i].head = pState->address[i * 2 + 0];
        data_02042418[i].tail = pState->address[i * 2 + 1];
    }
}
