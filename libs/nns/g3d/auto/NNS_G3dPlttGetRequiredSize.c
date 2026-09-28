

/* NNS_G3dPlttGetRequiredSize -- NitroSystem kernel.c: NNS_G3dPlttGetRequiredSize. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

u32 NNS_G3dPlttGetRequiredSize (const NNSG3dResTex * pTex)
{

    if (pTex) {
        return (u32)(pTex->plttInfo.sizePltt << 3);
    } else {
        return 0;
    }
}
