#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef struct NNSG2dBinaryFileHeader {
    u32 signature;
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
} NNSG2dBinaryFileHeader;
typedef struct NNSG2dBinaryBlockHeader {
    u32 kind;
    u32 size;
} NNSG2dBinaryBlockHeader;

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
