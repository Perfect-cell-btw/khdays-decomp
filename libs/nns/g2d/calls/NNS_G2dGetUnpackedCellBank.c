

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_G2dUnpackNCE(NNSG2dCellDataBank * pCellData);
NNSG2dBinaryBlockHeader * NNS_G2dFindBinaryBlock(NNSG2dBinaryFileHeader * pBinFileHeader, u32 signature);
extern void NNS_G2dUnpackNCE (NNSG2dCellDataBank * pCellData);

/* NNS_G2dGetUnpackedCellBank -- NitroSystem g2d_NOB_load.c: NNS_G2dGetUnpackedCellBank. */
BOOL NNS_G2dGetUnpackedCellBank (void * pNcerFile, NNSG2dCellDataBank ** ppCellBank)
{

    {
        NNSG2dBinaryFileHeader * pBinFile = (NNSG2dBinaryFileHeader *)pNcerFile;
        {
            NNSG2dCellDataBankBlock * pBinBlk =
                (NNSG2dCellDataBankBlock *)NNS_G2dFindBinaryBlock(pBinFile,
                                                                  NNS_G2D_BLKSIG_CELLBANK);
            if (pBinBlk) {
                NNS_G2dUnpackNCE((void *)&pBinBlk->cellDataBank);
                *ppCellBank = &pBinBlk->cellDataBank;
                return TRUE;
            } else {
                *ppCellBank = NULL;
                return FALSE;

            }
        }
    }
}
