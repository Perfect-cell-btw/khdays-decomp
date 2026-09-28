

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void NNS_G3dMdlSetMdlPolygonID(NNSG3dResMdl * pMdl, u32 matID, int polygonID);
extern void NNS_G3dMdlSetMdlPolygonID (NNSG3dResMdl * pMdl, u32 matID, int polygonID);

/* NNS_G3dMdlSetMdlPolygonIDAll -- NitroSystem model.c: NNS_G3dMdlSetMdlPolygonIDAll. */
void NNS_G3dMdlSetMdlPolygonIDAll (NNSG3dResMdl * pMdl, int polygonID)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlPolygonID(pMdl, matID, polygonID);
    }
}
