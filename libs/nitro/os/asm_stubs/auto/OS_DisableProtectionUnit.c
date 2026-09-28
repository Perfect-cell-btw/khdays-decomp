/* NitroSDK original assembly (libraries/os/src/os_protectionUnit.c). */

#include "nitro/types.h"
#include "nitro/hw.h"

asm void OS_DisableProtectionUnit (void)
{
    mrc p15, 0, r0, c1, c0, 0
    bic r0, r0, #HW_C1_PROTECT_UNIT_ENABLE
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}
