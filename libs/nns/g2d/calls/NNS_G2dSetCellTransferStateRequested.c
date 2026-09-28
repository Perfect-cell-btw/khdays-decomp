

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

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
