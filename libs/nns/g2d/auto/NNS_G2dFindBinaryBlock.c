

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* NNS_G2dFindBinaryBlock -- NitroSystem g2d_Load.c: NNS_G2dFindBinaryBlock. */
NNSG2dBinaryBlockHeader * NNS_G2dFindBinaryBlock (NNSG2dBinaryFileHeader * pBinFileHeader, u32 signature)
{

    {
        NNSG2dBinaryBlockHeader * pCursor = (NNSG2dBinaryBlockHeader *)((u32)pBinFileHeader + (u32)pBinFileHeader->headerSize);

        u16 count = 0;
        while (count < pBinFileHeader->dataBlocks) {

            if (pCursor->kind == signature) {
                return pCursor;
            }
            pCursor = (NNSG2dBinaryBlockHeader *)((u32)pCursor + pCursor->size);
            count++;
        }
    }

    return NULL;
}
