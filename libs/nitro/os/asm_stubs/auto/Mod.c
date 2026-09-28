
/* Nintendo DS BIOS signed divide/remainder veneer. */

#include "nitro/types.h"

asm s32 Mod(register s32 numerator, register s32 denominator)
{
    swi 0x09
    add r0, r1, #0
    bx lr
}
