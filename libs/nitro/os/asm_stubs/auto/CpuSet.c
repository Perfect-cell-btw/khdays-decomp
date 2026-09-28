
/* Nintendo DS BIOS SWI 0x0b veneer. */

#include "nitro/types.h"

asm void CpuSet(register const void *source, register void *destination,
                register u32 control)
{
    swi 0x0b
    bx lr
}
