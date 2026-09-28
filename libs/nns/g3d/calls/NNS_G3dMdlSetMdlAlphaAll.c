

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void NNS_G3dMdlSetMdlAlpha(NNSG3dResMdl * pMdl, u32 matID, int alpha);
extern void NNS_G3dMdlSetMdlAlpha (NNSG3dResMdl * pMdl, u32 matID, int alpha);

/* NNS_G3dMdlSetMdlAlphaAll -- NitroSystem model.c: NNS_G3dMdlSetMdlAlphaAll. */
void NNS_G3dMdlSetMdlAlphaAll (NNSG3dResMdl * pMdl, int alpha)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlAlpha(pMdl, matID, alpha);
    }
}
