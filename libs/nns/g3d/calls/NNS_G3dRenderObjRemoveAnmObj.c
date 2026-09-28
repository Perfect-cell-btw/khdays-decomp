

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

#define SDK_WARNING(exp, ...) (void) ((exp) || (OSi_Warning(__FILE__, __LINE__, __VA_ARGS__), 0))

inline void NNS_G3dRenderObjSetFlag(NNSG3dRenderObj * pRenderObj, NNSG3dRenderObjFlag flag);
inline void NNS_G3dRenderObjSetFlag (NNSG3dRenderObj * pRenderObj, NNSG3dRenderObjFlag flag)
{
    pRenderObj->flag |= flag;
}
extern BOOL removeLink_ (NNSG3dAnmObj ** l, NNSG3dAnmObj * item);

/* NNS_G3dRenderObjRemoveAnmObj -- NitroSystem kernel.c: NNS_G3dRenderObjRemoveAnmObj. */
void NNS_G3dRenderObjRemoveAnmObj (NNSG3dRenderObj * pRenderObj, NNSG3dAnmObj * pAnmObj)
{

    if (removeLink_(&pRenderObj->anmMat, pAnmObj) ||
        removeLink_(&pRenderObj->anmJnt, pAnmObj) ||
        removeLink_(&pRenderObj->anmVis, pAnmObj)) {
        NNS_G3dRenderObjSetFlag(pRenderObj, NNS_G3D_RENDEROBJ_FLAG_HINT_OBSOLETE);
        return;
    }

    NNS_G3D_WARNING(0, "An AnmObj was not removed in NNS_G3dRenderObjRemoveAnmObj");
}
