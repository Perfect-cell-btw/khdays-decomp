/* NitroSDK original assembly (libraries/os/src/os_system.c). */

#include "nitro/types.h"
#include "nitro/hw.h"

typedef unsigned int OSIntrMode;

asm OSIntrMode OS_EnableInterrupts (void)
{
    mrs r0, cpsr
    bic r1, r0, #HW_PSR_IRQ_DISABLE
    msr cpsr_c, r1
    and r0, r0, #HW_PSR_IRQ_DISABLE
    bx lr
}
