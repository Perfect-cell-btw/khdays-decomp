

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

NNSG2dBinaryBlockHeader * NNS_G2dFindBinaryBlock(NNSG2dBinaryFileHeader * pBinFileHeader, u32 signature);

/* NNS_G2dGetUnpackedScreenData -- NitroSystem g2d_NSC_load.c: NNS_G2dGetUnpackedScreenData. */
BOOL NNS_G2dGetUnpackedScreenData (void * pNscrFile, NNSG2dScreenData ** ppScrData)
{

    {
        NNSG2dBinaryFileHeader * pBinFile = (NNSG2dBinaryFileHeader *)pNscrFile;
        {
            NNSG2dScreenDataBlock * pBinBlk =
                (NNSG2dScreenDataBlock *)NNS_G2dFindBinaryBlock(pBinFile,
                                                                NNS_G2D_BINBLK_SIG_SCRDATA);
            if (pBinBlk) {

                *ppScrData = &(pBinBlk->screenData);

                return TRUE;
            } else {
                *ppScrData = NULL;
                return FALSE;

            }
        }
    }
}
