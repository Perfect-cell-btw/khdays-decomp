/* NitroSDK original assembly (libraries/os/src/os_cache.c). */

#include "nitro/types.h"

asm void IC_InvalidateAll (void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c5, 0
    bx lr
}
