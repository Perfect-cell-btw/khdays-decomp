

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

/* NNS_G3dReleaseMdlPltt -- NitroSystem kernel.c: NNS_G3dReleaseMdlPltt. */
void NNS_G3dReleaseMdlPltt (NNSG3dResMdl * pMdl)
{
    NNSG3dResMat * mat;
    NNSG3dResDict * dictPltt;
    u32 i;

    mat = NNS_G3dGetMat(pMdl);
    dictPltt = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictPlttToMatList);
    for (i = 0; i < dictPltt->numEntry; ++i) {
        NNSG3dResDictPlttToMatIdxData * data =
            (NNSG3dResDictPlttToMatIdxData *) NNS_G3dGetResDataByIdx(dictPltt, i);

        if (data->flag & 1) {
            data->flag &= ~1;
        }
    }
}
