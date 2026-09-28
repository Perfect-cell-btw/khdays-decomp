

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
inline NNSG3dResMat * NNS_G3dGetMat(const NNSG3dResMdl * mdl);
inline void * NNS_G3dGetResDataByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;
    if (dict != NULL && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)(&hdr->data[0] + hdr->sizeUnit * idx);
    } else {
        return NULL ;
    }
}
inline NNSG3dResMat * NNS_G3dGetMat (const NNSG3dResMdl * mdl)
{
    if (mdl && mdl->ofsMat != 0)
        return (NNSG3dResMat *)((u8 *)mdl + mdl->ofsMat);
    else
        return NULL ;
}
extern void releaseMdlTex_Internal_ (NNSG3dResMat * pMat, NNSG3dResDictTexToMatIdxData * pData);

/* NNS_G3dReleaseMdlTex -- NitroSystem kernel.c: NNS_G3dReleaseMdlTex. */
void NNS_G3dReleaseMdlTex (NNSG3dResMdl * pMdl)
{
    NNSG3dResMat * mat;
    NNSG3dResDict * dictTex;
    u32 i;

    mat = NNS_G3dGetMat(pMdl);
    dictTex = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictTexToMatList);

    for (i = 0; i < dictTex->numEntry; ++i) {
        NNSG3dResDictTexToMatIdxData * data =
            (NNSG3dResDictTexToMatIdxData *) NNS_G3dGetResDataByIdx(dictTex, i);

        if (data->flag & 1) {
            releaseMdlTex_Internal_(mat, data);
        }
    }
}
