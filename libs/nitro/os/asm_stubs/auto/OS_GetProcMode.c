/* NitroSDK original assembly (libraries/os/src/os_system.c). */

#include "nitro/types.h"
#include "nitro/os.h"

asm OSProcMode OS_GetProcMode (void)
{
    mrs r0, cpsr
    and r0, r0, #HW_PSR_CPU_MODE_MASK
    bx lr
}
