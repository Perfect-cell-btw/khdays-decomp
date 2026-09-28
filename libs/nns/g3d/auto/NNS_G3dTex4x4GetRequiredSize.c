

/* NNS_G3dTex4x4GetRequiredSize -- NitroSystem kernel.c: NNS_G3dTex4x4GetRequiredSize. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

u32 NNS_G3dTex4x4GetRequiredSize (const NNSG3dResTex * pTex)
{

    if (pTex) {
        return (u32)(pTex->tex4x4Info.sizeTex << 3);
    } else {
        return 0;
    }
}
