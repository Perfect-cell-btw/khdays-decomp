

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nitro/gx.h"
#include "nnsys/g3d.h"

void func_02016978(NNSG3dResMdl * pMdl, u32 matID, GXRgb col);
extern void func_02016978 (NNSG3dResMdl * pMdl, u32 matID, GXRgb col);

/* NNS_G3dMdlSetMdlDiffAll -- NitroSystem model.c: NNS_G3dMdlSetMdlDiffAll. */
void NNS_G3dMdlSetMdlDiffAll (NNSG3dResMdl * pMdl, GXRgb col)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        func_02016978(pMdl, matID, col);
    }
}
