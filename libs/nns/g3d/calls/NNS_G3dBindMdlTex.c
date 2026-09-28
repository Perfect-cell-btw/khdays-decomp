

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/pxi.h"
#include "nitro/spi.h"
#include "nitro/rtc.h"
#include "nitro/wm.h"
#include "nnsys/g3d.h"

typedef enum WVRResult {
    WVR_RESULT_SUCCESS = 0,
    WVR_RESULT_OPERATING,
    WVR_RESULT_DISABLE,
    WVR_RESULT_INVALID_PARAM,
    WVR_RESULT_FIFO_ERROR,
    WVR_RESULT_ILLEGAL_STATUS,
    WVR_RESULT_VRAM_LOCKED,
    WVR_RESULT_FATAL_ERROR,
    WVR_RESULT_MAX
} WVRResult;
typedef void (*WVRCallbackFunc) (void * arg, WVRResult result);
typedef BOOL (*MBFakeCompareGGIDCallbackFunc) (WMStartScanCallback * arg, u32 defaultGGID);
inline const NNSG3dResName * NNS_G3dGetResNameByIdx(const NNSG3dResDict * dict, u32 idx);
inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
void * NNS_G3dGetResDataByName(const NNSG3dResDict * dict, const NNSG3dResName * name);
inline NNSG3dResMat * NNS_G3dGetMat(const NNSG3dResMdl * mdl);
inline NNSG3dResDictTexData * NNS_G3dGetTexDataByName(const NNSG3dResTex * tex, const NNSG3dResName * name);
inline const NNSG3dResName * NNS_G3dGetResNameByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;
    if (dict != NULL && idx < dict->numEntry) {
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (NNSG3dResName *)((u8 *)hdr +
                                 hdr->ofsName +
                                 sizeof(NNSG3dResName) * idx);
    } else {
        return NULL ;
    }
}
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
inline NNSG3dResDictTexData * NNS_G3dGetTexDataByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    if (tex)
        return (NNSG3dResDictTexData *)NNS_G3dGetResDataByName(&tex->dict, name);
    else
        return NULL ;
}
extern void bindMdlTex_Internal_ (NNSG3dResMat * pMat, NNSG3dResDictTexToMatIdxData * pBindData, const NNSG3dResTex * pTex, const NNSG3dResDictTexData * pTexData);

/* NNS_G3dBindMdlTex -- NitroSystem kernel.c: NNS_G3dBindMdlTex. */
BOOL NNS_G3dBindMdlTex (NNSG3dResMdl * pMdl, const NNSG3dResTex * pTex)
{
    NNSG3dResMat * mat;
    NNSG3dResDict * dictTex;
    u32 i;
    BOOL result = TRUE;

    mat = NNS_G3dGetMat(pMdl);
    dictTex = (NNSG3dResDict *)((u8 *)mat + mat->ofsDictTexToMatList);

    for (i = 0; i < dictTex->numEntry; ++i) {
        const NNSG3dResName * name = NNS_G3dGetResNameByIdx(dictTex, i);
        const NNSG3dResDictTexData * texData = NNS_G3dGetTexDataByName(pTex, name);

        if (texData) {
            NNSG3dResDictTexToMatIdxData * data =
                (NNSG3dResDictTexToMatIdxData *) NNS_G3dGetResDataByIdx(dictTex, i);

            if (!(data->flag & 1)) {
                bindMdlTex_Internal_(mat, data, pTex, texData);
            }
        } else {
            result = FALSE;
        }
    }
    return result;
}
