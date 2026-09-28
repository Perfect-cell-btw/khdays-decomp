

#include "nitro/types.h"
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

/* NNS_G3dGetAnmByIdx -- NitroSystem res_struct_accessor_anm.c: NNS_G3dGetAnmByIdx. */
void * NNS_G3dGetAnmByIdx (const void * pRes, u32 idx)
{

    if (pRes) {
        const NNSG3dResFileHeader * header;
        const NNSG3dResAnmSet * anmSet;
        const NNSG3dResDictAnmSetData * anmSetData;
        u32 * blks;

        header = (const NNSG3dResFileHeader *) pRes;
        blks = (u32 *)((u8 *)header + header->headerSize);

        anmSet = (const NNSG3dResAnmSet *)((u8 *)header + blks[0]);
        anmSetData = (const NNSG3dResDictAnmSetData *)NNS_G3dGetResDataByIdx(&anmSet->dict, idx);

        if (anmSetData) {
            return (void *)((u8 *)anmSet + anmSetData->offset);
        }
    }

    return NULL;
}
