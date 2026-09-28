

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

extern void addLink_ (NNSG3dAnmObj ** l, NNSG3dAnmObj * item);
extern void updateHintVec_ (u32 * pVec, const NNSG3dAnmObj * pAnmObj);

/* NNS_G3dRenderObjAddAnmObj -- NitroSystem kernel.c: NNS_G3dRenderObjAddAnmObj. */
void NNS_G3dRenderObjAddAnmObj (NNSG3dRenderObj * pRenderObj, NNSG3dAnmObj * pAnmObj)
{
    const NNSG3dResAnmHeader * hdr;

    if (pAnmObj && pAnmObj->resAnm) {
        hdr = (const NNSG3dResAnmHeader *)pAnmObj->resAnm;

        switch (hdr->category0) {
        case 'M':
            updateHintVec_(&pRenderObj->hintMatAnmExist[0], pAnmObj);
            addLink_(&pRenderObj->anmMat, pAnmObj);
            break;
        case 'J':
            updateHintVec_(&pRenderObj->hintJntAnmExist[0], pAnmObj);
            addLink_(&pRenderObj->anmJnt, pAnmObj);
            break;
        case 'V':
            updateHintVec_(&pRenderObj->hintVisAnmExist[0], pAnmObj);
            addLink_(&pRenderObj->anmVis, pAnmObj);
            break;
        default:
            break;
        }
    }
}
