

#include "nitro/types.h"
#include "nitro/fx_types.h"
#include "nitro/os.h"
#include "nnsys/fnd.h"
#include "nnsys/g3d.h"

u32 NTRi_GetRegionTableSize(const void * pAnm, const NNSG3dResMdl * pMdl);
void * NNS_FndAllocFromAllocator(NNSFndAllocator * pAllocator, u32 size);

/* NNS_G3dAllocAnmObj -- NitroSystem mem.c: NNS_G3dAllocAnmObj. */
NNSG3dAnmObj * NNS_G3dAllocAnmObj (NNSFndAllocator * pAlloc, const void * pAnm, const NNSG3dResMdl * pMdl)
{
    u32 sz;

    sz = NTRi_GetRegionTableSize(pAnm, pMdl);
    return (NNSG3dAnmObj *) NNS_FndAllocFromAllocator(pAlloc, sz);
}
