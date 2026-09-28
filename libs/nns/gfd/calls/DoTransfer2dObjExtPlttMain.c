#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

typedef int (*MIDeviceReadFunction)(void * userdata, void * buffer, u32 offset, u32 length);
typedef int (*MIDeviceWriteFunction)(void * userdata, const void * buffer, u32 offset, u32 length);
void GX_BeginLoadOBJExtPltt(void);
void GX_LoadOBJExtPltt(const void * pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadOBJExtPltt(void);
typedef void * (*MIAllocatorAllocFunction)(void * userdata, u32 length, u32 alignment);
typedef void (*MIAllocatorFreeFunction)(void * userdata, void * buffer);

/* DoTransfer2dObjExtPlttMain -- NitroSystem gfd_VramTransferManager.c: DoTransfer2dObjExtPlttMain. */
void DoTransfer2dObjExtPlttMain (const void * pSrc, u32 offset, u32 szByte)
{
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(pSrc, offset, szByte);
    GX_EndLoadOBJExtPltt();
}
