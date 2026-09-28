/* NitroSDK original assembly (libraries/os/src/os_protectionRegion.c). */

#include "nitro/types.h"

asm void OS_SetProtectionRegion2 (u32 param)
{
    mcr p15, 0, r0, c6, c2, 0
    bx lr
}
