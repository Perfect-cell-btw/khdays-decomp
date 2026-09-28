

#include "nitro/types.h"
#include "nitro/os_types.h"
#include "nitro/hw.h"

typedef void *OSMessage;

typedef int PXIProc;
typedef struct OSSystemWork {
    u8 reserved[0x388];
    u32 pxiHandleChecker[2];      /* 0x388: fifo tags each processor has a callback for */
} OSSystemWork;
#define OS_GetSystemWork() ((OSSystemWork *)HW_MAIN_MEM_SYSTEM)

/* PXI_IsCallbackReady -- NitroSDK pxi_fifo.c: whether processor `proc` has registered a
 * fifo receive callback for `fifotag` (the shared-work bit set by PXI_SetFifoRecvCallback). */
BOOL PXI_IsCallbackReady(int fifotag, PXIProc proc)
{
    OSSystemWork *p = OS_GetSystemWork();
    return (p->pxiHandleChecker[proc] & (1UL << fifotag)) ? TRUE : FALSE;
}
