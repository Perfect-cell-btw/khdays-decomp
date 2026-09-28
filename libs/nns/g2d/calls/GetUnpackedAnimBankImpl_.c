

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void NNS_G2dUnpackNAN(NNSG2dAnimBankData * pData);
NNSG2dBinaryBlockHeader * NNS_G2dFindBinaryBlock(NNSG2dBinaryFileHeader * pBinFileHeader, u32 signature);
extern void NNS_G2dUnpackNAN (NNSG2dAnimBankData * pData);

/* GetUnpackedAnimBankImpl_ -- NitroSystem g2d_NAN_load.c: GetUnpackedAnimBankImpl_. */
BOOL GetUnpackedAnimBankImpl_ (void * pNanrFile, NNSG2dAnimBankData ** ppAnimBank)
{
    {
        NNSG2dBinaryFileHeader * pBinFile = (NNSG2dBinaryFileHeader *)pNanrFile;
        {
            NNSG2dAnimBankDataBlock * pAnimBankBlk =
                (NNSG2dAnimBankDataBlock *)NNS_G2dFindBinaryBlock(pBinFile,
                                                                  NNS_G2D_BLKSIG_ANIMBANK);
            if (pAnimBankBlk) {
                NNS_G2dUnpackNAN((void *)&pAnimBankBlk->animBankData);
                *ppAnimBank = &pAnimBankBlk->animBankData;
                return TRUE;
            }
        }
    }

    *ppAnimBank = NULL;
    return FALSE;
}
