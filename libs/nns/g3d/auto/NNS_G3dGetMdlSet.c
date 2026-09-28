

#include "nitro/types.h"
#include "nitro/os.h"
#include "nnsys/g3d.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

/* NNS_G3dGetMdlSet -- NitroSystem res_struct_accessor.c: NNS_G3dGetMdlSet. */
NNSG3dResMdlSet * NNS_G3dGetMdlSet (const NNSG3dResFileHeader * header)
{
    u32 * blks;

    blks = (u32 *)((u8 *)header + header->headerSize);
    return (NNSG3dResMdlSet *)((u8 *)header + blks[0]);
}
