

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
BOOL NNS_G3dBindMdlTex(NNSG3dResMdl * pMdl, const NNSG3dResTex * pTex);
BOOL NNS_G3dBindMdlPltt(NNSG3dResMdl * pMdl, const NNSG3dResTex * pTex);
inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
inline NNSG3dResMdl * NNS_G3dGetMdlByIdx(const NNSG3dResMdlSet * mdlSet, u32 idx);
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
inline NNSG3dResMdl * NNS_G3dGetMdlByIdx (const NNSG3dResMdlSet * mdlSet, u32 idx)
{
    NNSG3dResDictMdlSetData * data;
    if (mdlSet) {
        data = (NNSG3dResDictMdlSetData *)NNS_G3dGetResDataByIdx(&mdlSet->dict, idx);
        if (data) {
            return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
        }
    }
    return NULL ;
}
extern BOOL NNS_G3dBindMdlTex (NNSG3dResMdl * pMdl, const NNSG3dResTex * pTex);
extern BOOL NNS_G3dBindMdlPltt (NNSG3dResMdl * pMdl, const NNSG3dResTex * pTex);

/* NNS_G3dBindMdlSet -- NitroSystem kernel.c: NNS_G3dBindMdlSet. */
BOOL NNS_G3dBindMdlSet (NNSG3dResMdlSet * pMdlSet, const NNSG3dResTex * pTex)
{
    u32 i;
    BOOL result = TRUE;

    for (i = 0; i < pMdlSet->dict.numEntry; ++i) {
        NNSG3dResMdl * mdl = NNS_G3dGetMdlByIdx(pMdlSet, i);

        result &= NNS_G3dBindMdlTex(mdl, pTex);
        result &= NNS_G3dBindMdlPltt(mdl, pTex);
    }
    return result;
}
