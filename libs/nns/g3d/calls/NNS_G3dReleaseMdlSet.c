

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

void NNS_G3dReleaseMdlTex(NNSG3dResMdl * pMdl);
void NNS_G3dReleaseMdlPltt(NNSG3dResMdl * pMdl);
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
extern void NNS_G3dReleaseMdlTex (NNSG3dResMdl * pMdl);
extern void NNS_G3dReleaseMdlPltt (NNSG3dResMdl * pMdl);

/* NNS_G3dReleaseMdlSet -- NitroSystem kernel.c: NNS_G3dReleaseMdlSet. */
void NNS_G3dReleaseMdlSet (NNSG3dResMdlSet * pMdlSet)
{
    u32 i;

    for (i = 0; i < pMdlSet->dict.numEntry; ++i) {
        NNSG3dResMdl * mdl = NNS_G3dGetMdlByIdx(pMdlSet, i);

        NNS_G3dReleaseMdlTex(mdl);
        NNS_G3dReleaseMdlPltt(mdl);
    }
}
