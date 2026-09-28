

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* NNSi_G2dUnpackUserExCellAttrBank -- NitroSystem g2d_Load.c: NNSi_G2dUnpackUserExCellAttrBank. */
void NNSi_G2dUnpackUserExCellAttrBank (NNSG2dUserExCellAttrBank * pCellAttrBank)
{
    u16 i;

    pCellAttrBank->pCellAttrArray
        = NNS_G2D_UNPACK_OFFSET_PTR(pCellAttrBank->pCellAttrArray,
                                    pCellAttrBank);
    for (i = 0; i < pCellAttrBank->numCells; i++) {
        pCellAttrBank->pCellAttrArray[i].pAttr
            = NNS_G2D_UNPACK_OFFSET_PTR(pCellAttrBank->pCellAttrArray[i].pAttr,
                                        pCellAttrBank);
    }
}
