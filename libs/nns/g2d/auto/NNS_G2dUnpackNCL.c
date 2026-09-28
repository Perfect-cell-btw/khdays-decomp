

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g2d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* NNS_G2dUnpackNCL -- NitroSystem g2d_NCL_load.c: NNS_G2dUnpackNCL. */
void NNS_G2dUnpackNCL (NNSG2dPaletteData * pPlttData)
{

    pPlttData->pRawData = NNS_G2D_UNPACK_OFFSET_PTR(pPlttData->pRawData, pPlttData);

}
