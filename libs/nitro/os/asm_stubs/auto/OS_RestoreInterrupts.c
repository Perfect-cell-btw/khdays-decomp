/* NitroSDK original assembly (libraries/os/src/os_system.c). */

#include "nitro/types.h"
#include "nitro/hw.h"

typedef unsigned int OSIntrMode;

asm OSIntrMode OS_RestoreInterrupts (register OSIntrMode state)
{
    mrs r1, cpsr
    bic r2, r1, #HW_PSR_IRQ_DISABLE
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #HW_PSR_IRQ_DISABLE
    bx lr
}
