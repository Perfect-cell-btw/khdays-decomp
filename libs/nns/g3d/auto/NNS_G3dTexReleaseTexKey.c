

/* NNS_G3dTexReleaseTexKey -- NitroSystem kernel.c: NNS_G3dTexReleaseTexKey. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void NNS_G3dTexReleaseTexKey (NNSG3dResTex * pTex, NNSG3dTexKey * texKey, NNSG3dTexKey * tex4x4Key)
{

    if (texKey) {
        pTex->texInfo.flag &= ~NNS_G3D_RESTEX_LOADED;
        *texKey = pTex->texInfo.vramKey;
        pTex->texInfo.vramKey = 0;
    }

    if (tex4x4Key) {
        pTex->tex4x4Info.flag &= ~NNS_G3D_RESTEX4x4_LOADED;
        *tex4x4Key = pTex->tex4x4Info.vramKey;
        pTex->tex4x4Info.vramKey = 0;
    }
}
