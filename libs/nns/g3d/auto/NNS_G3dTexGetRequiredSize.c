

/* NNS_G3dTexGetRequiredSize -- NitroSystem kernel.c: NNS_G3dTexGetRequiredSize. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

u32 NNS_G3dTexGetRequiredSize (const NNSG3dResTex * pTex)
{

    if (pTex) {
        return (u32)(pTex->texInfo.sizeTex << 3);
    } else {
        return 0;
    }
}
