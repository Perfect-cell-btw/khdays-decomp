

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/pxi.h"
#include "nnsys/g3d.h"

inline void * NNS_G3dGetResDataByIdx(const NNSG3dResDict * dict, u32 idx);
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

/* NNSi_G3dGetTexPatAnmDataByIdx -- NitroSystem res_struct_accessor_anm.c: NNSi_G3dGetTexPatAnmDataByIdx. */
const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx (const NNSG3dResTexPatAnm * pPatAnm, u32 idx)
{
    return (const NNSG3dResDictTexPatAnmData *)NNS_G3dGetResDataByIdx(&pPatAnm->dict, idx);
}
