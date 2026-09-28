#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef struct NNSG2dUserExDataBlock {
    u32 blkTypeID;
    u32 blkSize;
} NNSG2dUserExDataBlock;
typedef struct NNSG2dUserExCellAttr {
    u32 * pAttr;
} NNSG2dUserExCellAttr;
typedef struct NNSG2dUserExCellAttrBank {
    u16 numCells;
    u16 numAttribute;
    NNSG2dUserExCellAttr * pCellAttrArray;
} NNSG2dUserExCellAttrBank;
void NNSi_G2dUnpackUserExCellAttrBank(NNSG2dUserExCellAttrBank * pCellAttrBank);

/* UnpackExtendedData_ -- NitroSystem g2d_NOB_load.c: UnPackExtendedData_. */
void UnpackExtendedData_ (void * pExData)
{
    {
        NNSG2dUserExDataBlock * pBlk = (NNSG2dUserExDataBlock *)pExData;
        NNSG2dUserExCellAttrBank * pCellAttrBank = (NNSG2dUserExCellAttrBank *)(pBlk + 1);

        NNSi_G2dUnpackUserExCellAttrBank(pCellAttrBank);
    }
}
