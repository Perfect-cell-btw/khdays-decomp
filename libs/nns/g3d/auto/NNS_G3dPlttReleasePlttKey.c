

/* NNS_G3dPlttReleasePlttKey -- NitroSystem kernel.c: NNS_G3dPlttReleasePlttKey. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

NNSG3dPlttKey NNS_G3dPlttReleasePlttKey (NNSG3dResTex * pTex)
{
    u32 rval;

    pTex->plttInfo.flag &= ~NNS_G3D_RESPLTT_LOADED;

    rval = pTex->plttInfo.vramKey;
    pTex->plttInfo.vramKey = 0;

    return rval;
}
