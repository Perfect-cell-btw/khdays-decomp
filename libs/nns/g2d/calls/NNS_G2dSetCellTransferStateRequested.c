#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef enum NNS_G2D_VRAM_TYPE {
    NNS_G2D_VRAM_TYPE_3DMAIN = 0,
    NNS_G2D_VRAM_TYPE_2DMAIN = 1,
    NNS_G2D_VRAM_TYPE_2DSUB  = 2,
    NNS_G2D_VRAM_TYPE_2DBOTH = 3,
    NNS_G2D_VRAM_TYPE_MAX    = 3
} NNS_G2D_VRAM_TYPE;
typedef struct NNSG2dVRamLocation {
    u32 baseAddrOfVram[NNS_G2D_VRAM_TYPE_MAX];
} NNSG2dVRamLocation;
typedef struct NNSG2dCellTransferState {
    NNSG2dVRamLocation dstVramLocation;
    u32 szDst;
    const void * pSrcNCGR;
    const void * pSrcNCBR;
    u32 szSrcData;
    BOOL bActive;
    u32 bDrawn;
    u32 bTransferRequested;
    u32 srcOffset;
    u32 szByte;
} NNSG2dCellTransferState;
NNSG2dCellTransferState * GlobalArrayEntryPtr30(u32 handle);
extern NNSG2dCellTransferState * GlobalArrayEntryPtr30 (u32 handle);

/* NNS_G2dSetCellTransferStateRequested -- NitroSystem g2d_CellTransferManager.c: NNS_G2dSetCellTransferStateRequested. */
void NNS_G2dSetCellTransferStateRequested (u32 handle, u32 srcOffset, u32 szByte)
{

    {
        NNSG2dCellTransferState * pState = GlobalArrayEntryPtr30(handle);

        pState->bTransferRequested = 0xFFFFFFFF;
        pState->srcOffset = srcOffset;
        pState->szByte = szByte;
    }
}
