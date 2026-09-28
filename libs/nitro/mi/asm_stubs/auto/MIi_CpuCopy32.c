
/* NitroSDK word copy primitive. */

#include "nitro/types.h"

asm void MIi_CpuCopy32(register const void *source,
                       register void *destination, register u32 size)
{
    add     ip, r1, r2
copyNextWord:
    cmp     r1, ip
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt     copyNextWord
    bx      lr
}
