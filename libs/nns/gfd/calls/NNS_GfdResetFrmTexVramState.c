#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define NNS_GFD_NUM_TEX_VRAM_REGION 5

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
typedef struct NNSGfdFrmTexVramMnager {
    u16 numSlot;
} NNSGfdFrmTexVramMnager;
extern NNSGfdFrmTexVramMnager data_02047360;
extern NNSGfdFrmTexRegionState data_02042418[5 ];
static inline void ResetRegionNormal_ (NNSGfdFrmTexRegionState * pRegion)
{
    pRegion->head = 0x0;
    pRegion->tail = 0x20000 ;
}
static inline void ResetRegionHalf_ (NNSGfdFrmTexRegionState * pRegion)
{
    pRegion->head = 0x0;
    pRegion->tail = 0x20000 / 2;
}

/* NNS_GfdResetFrmTexVramState -- NitroSystem gfd_FrameTexVramMan.c: NNS_GfdResetFrmTexVramState. */
void NNS_GfdResetFrmTexVramState (void)
{
    int i;
    u16 numSlot = data_02047360.numSlot;

    const numRegion = (numSlot > 1) ? numSlot + 1 : numSlot + 0;

    for (i = 0; i < NNS_GFD_NUM_TEX_VRAM_REGION; i++) {
        if ( i < numRegion ) {
            data_02042418[i].bActive = TRUE;
        } else {
            data_02042418[i].bActive = FALSE;
        }

        if ( data_02042418[i].bHalfSize ) {
            ResetRegionHalf_(&data_02042418[i]);
        } else {
            ResetRegionNormal_(&data_02042418[i]);
        }
    }
}
