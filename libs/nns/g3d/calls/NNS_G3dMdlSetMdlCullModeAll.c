

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

typedef enum {
    GX_CULL_ALL      = 0,
    GX_CULL_FRONT    = 1,
    GX_CULL_BACK     = 2,
    GX_CULL_NONE     = 3
} GXCull;
void NNS_G3dMdlSetMdlCullMode(NNSG3dResMdl * pMdl, u32 matID, GXCull cullMode);
extern void NNS_G3dMdlSetMdlCullMode (NNSG3dResMdl * pMdl, u32 matID, GXCull cullMode);

/* NNS_G3dMdlSetMdlCullModeAll -- NitroSystem model.c: NNS_G3dMdlSetMdlCullModeAll. */
void NNS_G3dMdlSetMdlCullModeAll (NNSG3dResMdl * pMdl, GXCull cullMode)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlCullMode(pMdl, matID, cullMode);
    }
}
