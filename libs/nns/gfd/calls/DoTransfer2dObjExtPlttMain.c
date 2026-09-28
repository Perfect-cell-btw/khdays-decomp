

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"

void GX_BeginLoadOBJExtPltt(void);
void GX_LoadOBJExtPltt(const void * pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadOBJExtPltt(void);

/* DoTransfer2dObjExtPlttMain -- NitroSystem gfd_VramTransferManager.c: DoTransfer2dObjExtPlttMain. */
void DoTransfer2dObjExtPlttMain (const void * pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}
