/* NitroSDK original assembly (libraries/os/src/os_cache.c). */

#include "nitro/types.h"

asm void DC_InvalidateAll (void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c6, 0
    bx lr
}
