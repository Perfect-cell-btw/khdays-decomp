/* NitroSDK original assembly (libraries/os/src/os_system.c). */

#include "nitro/types.h"
#include "nitro/os.h"

asm OSIntrMode_Irq OS_GetCpsrIrq (void)
{
    mrs r0, cpsr
    and r0, r0, #HW_PSR_IRQ_DISABLE
    bx lr
}
