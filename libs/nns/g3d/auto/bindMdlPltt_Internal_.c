

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

inline u32 NNS_GfdGetTexKeyAddr (NNSGfdTexKey memKey)
{
    return (u32)(((0x0000FFFF & memKey)) << 3 );
}
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

/* bindMdlPltt_Internal_ -- NitroSystem kernel.c: bindMdlPltt_Internal_. */
void bindMdlPltt_Internal_ (NNSG3dResMat * pMat, NNSG3dResDictPlttToMatIdxData * pBindData, const NNSG3dResTex * pTex, const NNSG3dResDictPlttData * pPlttData)
{
    u8 * base = (u8 *)pMat + pBindData->offset;
    u16 plttBase = pPlttData->offset;
    u16 vramOffset = (u16)(NNS_GfdGetTexKeyAddr(pTex->plttInfo.vramKey) >> NNS_GFD_TEXKEY_ADDR_SHIFT);
    u32 j;

    if (!(pPlttData->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }

    for (j = 0; j < pBindData->numIdx; ++j) {
        NNSG3dResMatData * matData = NNS_G3dGetMatDataByIdx(pMat, *(base + j));
        matData->texPlttBase = (u16)(plttBase + vramOffset);
    }

    pBindData->flag |= 1;
}
