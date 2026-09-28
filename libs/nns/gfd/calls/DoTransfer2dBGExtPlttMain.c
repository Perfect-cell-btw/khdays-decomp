

#include "nitro/types.h"
#include "nitro/mi.h"
#include "nitro/os.h"

#define offsetof(type, member) ((u32)&(((type *)0)->member))

void GX_BeginLoadBGExtPltt(void);
void GX_LoadBGExtPltt(const void * pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadBGExtPltt(void);

/* DoTransfer2dBGExtPlttMain -- NitroSystem gfd_VramTransferManager.c: DoTransfer2dBGExtPlttMain. */
void DoTransfer2dBGExtPlttMain (const void * pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}
