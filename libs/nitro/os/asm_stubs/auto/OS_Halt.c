/* NitroSDK original assembly (libraries/os/src/os_terminate_proc.c). */

#include "nitro/types.h"

asm void OS_Halt(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
