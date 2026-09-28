

/* NNS_G3dRenderObjResetCallBack -- NitroSystem kernel.c: NNS_G3dRenderObjResetCallBack. */

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

void NNS_G3dRenderObjResetCallBack (NNSG3dRenderObj * pRenderObj)
{

    pRenderObj->cbFunc = NULL;
    pRenderObj->cbCmd = 0;
    pRenderObj->cbTiming = 0;
}
