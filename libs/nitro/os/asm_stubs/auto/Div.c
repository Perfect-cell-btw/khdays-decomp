
/* Nintendo DS BIOS signed divide veneer. */

#include "nitro/types.h"

asm s32 Div(register s32 numerator, register s32 denominator)
{
    swi 0x09
    bx lr
}
