

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

const NNSG2dCellData * NNS_G2dGetCellDataByIdx(const NNSG2dCellDataBank * pCellData, u16 idx);
extern void * GetPtrOamArrayHead_ (NNSG2dCellDataBank * pCellBank);
extern void UnpackExtendedData_ (void * pExData);
extern const NNSG2dCellData * NNS_G2dGetCellDataByIdx (const NNSG2dCellDataBank * pCellData, u16 idx);

/* NNS_G2dUnpackNCE -- NitroSystem g2d_NOB_load.c: NNS_G2dUnpackNCE. */
void NNS_G2dUnpackNCE (NNSG2dCellDataBank * pCellData)
{
    {
        pCellData->pCellDataArrayHead = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pCellDataArrayHead, pCellData);

        {
            void * pHeadOfOAMData = GetPtrOamArrayHead_(pCellData);

            u16 i;
            NNSG2dCellData * pCell = NULL;
            for (i = 0; i < pCellData->numCells; i++) {
                pCell = (NNSG2dCellData *)(NNS_G2dGetCellDataByIdx(pCellData, i));
                pCell->pOamAttrArray = NNS_G2D_UNPACK_OFFSET_PTR(pCell->pOamAttrArray, pHeadOfOAMData);
            }
        }

        if (pCellData->pVramTransferData != NULL) {
            NNSG2dVramTransferData * pVramTsfmData = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pVramTransferData, pCellData);

            pVramTsfmData->pCellTransferDataArray = NNS_G2D_UNPACK_OFFSET_PTR(pVramTsfmData->pCellTransferDataArray, pVramTsfmData);
            pCellData->pVramTransferData = pVramTsfmData;
        }

        if (pCellData->pExtendedData != NULL) {
            pCellData->pExtendedData = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pExtendedData, pCellData);
            UnpackExtendedData_(pCellData->pExtendedData);
        }

    }

}
