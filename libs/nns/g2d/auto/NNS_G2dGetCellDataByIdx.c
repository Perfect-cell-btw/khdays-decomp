

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

inline BOOL NNSi_G2dCellBankHasBR (const NNSG2dCellDataBank * pCellBank)
{
    return (BOOL)(pCellBank->cellBankAttr & 0x1 );
}

/* NNS_G2dGetCellDataByIdx -- NitroSystem g2d_NOB_load.c: NNS_G2dGetCellDataByIdx. */
const NNSG2dCellData * NNS_G2dGetCellDataByIdx (const NNSG2dCellDataBank * pCellData, u16 idx)
{

    if (idx >= pCellData->numCells) {
        return NULL;
    }

    if (NNSi_G2dCellBankHasBR(pCellData)) {
        const NNSG2dCellDataWithBR * pCellBR =
            (const NNSG2dCellDataWithBR *)(pCellData->pCellDataArrayHead) + idx;
        return &pCellBR->cellData;
    } else {
        return pCellData->pCellDataArrayHead + idx;
    }
}
