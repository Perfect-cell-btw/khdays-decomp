/* NitroSDK original assembly (libraries/os/src/os_tcm.c). */

#include "nitro/types.h"
#include "nitro/os.h"

asm u32 OS_GetDTCMAddress (void)
{
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, = OSi_TCM_REGION_BASE_MASK
    and r0, r0, r1
    bx lr
}
