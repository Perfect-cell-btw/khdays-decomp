
/* Nintendo DS BIOS SWI 0x0c veneer. */

#include "nitro/types.h"

asm void CpuFastSet(register const void *source, register void *destination,
                    register u32 control)
{
    swi 0x0c
    bx lr
}
