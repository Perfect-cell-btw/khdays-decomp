

/* NNS_G3dGetTex -- NitroSystem res_struct_accessor.c: NNS_G3dGetTex. */

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

NNSG3dResTex * NNS_G3dGetTex (const NNSG3dResFileHeader * header)
{
    u32 * blks;

    blks = (u32 *)((u8 *)header + header->headerSize);

    if (header->dataBlocks == 1) {
        if (header->sigVal == NNS_G3D_SIGNATURE_NSBTX) {
            return (NNSG3dResTex *)((u8 *)header + blks[0]);
        } else {
            return NULL;
        }
    } else {
        return (NNSG3dResTex *)((u8 *)header + blks[1]);
    }
}
