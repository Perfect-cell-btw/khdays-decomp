#include "nitro/types.h"
#include "nitro/os.h"

typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
void GX_BeginLoadBGExtPltt(void);
void GX_LoadBGExtPltt(const void * pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadBGExtPltt(void);
typedef void * (*MIAllocatorAllocFunction)(void * userdata, u32 length, u32 alignment);
typedef void (*MIAllocatorFreeFunction)(void * userdata, void * buffer);

/* DoTransfer2dBGExtPlttMain -- NitroSystem gfd_VramTransferManager.c: DoTransfer2dBGExtPlttMain. */
void DoTransfer2dBGExtPlttMain (const void * pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(pSrc, offset, szByte);
    GX_EndLoadBGExtPltt();
}
