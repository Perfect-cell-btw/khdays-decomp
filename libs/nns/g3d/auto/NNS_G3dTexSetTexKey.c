

/* NNS_G3dTexSetTexKey -- NitroSystem kernel.c: NNS_G3dTexSetTexKey. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void NNS_G3dTexSetTexKey (NNSG3dResTex * pTex, NNSG3dTexKey texKey, NNSG3dTexKey tex4x4Key)
{
    if (texKey > 0) {
        pTex->texInfo.vramKey = texKey;
    }

    if (tex4x4Key > 0) {
        pTex->tex4x4Info.vramKey = tex4x4Key;
    }
}
