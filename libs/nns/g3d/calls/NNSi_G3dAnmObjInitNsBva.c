

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

extern NNSG3dFuncAnmVis data_02042494;
inline NNSG3dResNodeInfo * NNS_G3dGetNodeInfo(const NNSG3dResMdl * mdl);
inline NNSG3dResNodeInfo * NNS_G3dGetNodeInfo (const NNSG3dResMdl * mdl)
{
    if (mdl)
        return (NNSG3dResNodeInfo *)&mdl->nodeInfo;
    else
        return NULL ;
}

/* NNSi_G3dAnmObjInitNsBva -- NitroSystem nsbva.c: NNSi_G3dAnmObjInitNsBva. */
void NNSi_G3dAnmObjInitNsBva (NNSG3dAnmObj * pAnmObj, void * pResAnm, const NNSG3dResMdl * pResMdl)
{
    u32 i;
    NNSG3dResVisAnm * visAnm;
    const NNSG3dResNodeInfo * jnt;

    visAnm = (NNSG3dResVisAnm *)pResAnm;
    jnt = NNS_G3dGetNodeInfo(pResMdl);
    pAnmObj->funcAnm = (void *) data_02042494;
    pAnmObj->numMapData = pResMdl->info.numNode;

    pAnmObj->resAnm = (void *)visAnm;

    for (i = 0; i < pAnmObj->numMapData; ++i) {
        pAnmObj->mapData[i] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
    }
}
