

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
inline NNSG3dResMatData * NNS_G3dGetMatDataByIdx(const NNSG3dResMat * mat, u32 idx);
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
inline NNSG3dResMatData * NNS_G3dGetMatDataByIdx (const NNSG3dResMat * mat, u32 idx)
{
    NNSG3dResDictMatData * data;
    if (mat) {
        data = (NNSG3dResDictMatData *)NNS_G3dGetResDataByIdx(&mat->dict, idx);
        if (data) {
            return (NNSG3dResMatData *)((u8 *)mat + data->offset);
        }
    }
    return NULL ;
}

/* releaseMdlTex_Internal_ -- NitroSystem kernel.c: releaseMdlTex_Internal_. */
void releaseMdlTex_Internal_ (NNSG3dResMat * pMat, NNSG3dResDictTexToMatIdxData * pData)
{
    u8 * base = (u8 *)pMat + pData->offset;
    u32 j;

    for (j = 0; j < pData->numIdx; ++j) {

        NNSG3dResMatData * matData = NNS_G3dGetMatDataByIdx(pMat, *(base + j));

        matData->texImageParam &= REG_G3_TEXIMAGE_PARAM_TGEN_MASK |
                                  REG_G3_TEXIMAGE_PARAM_FT_MASK | REG_G3_TEXIMAGE_PARAM_FS_MASK |
                                  REG_G3_TEXIMAGE_PARAM_RT_MASK | REG_G3_TEXIMAGE_PARAM_RS_MASK;
        matData->magH = matData->magW = FX32_ONE;
    }

    pData->flag &= ~1;
}
