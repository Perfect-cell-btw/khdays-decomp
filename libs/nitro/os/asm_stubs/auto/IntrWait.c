#include "nitro/types.h"

/* Nintendo DS BIOS SWI 0x04 veneer. */
asm void IntrWait(register int clearPending, register u32 interruptMask)
{
    swi 0x04
    bx lr
}
