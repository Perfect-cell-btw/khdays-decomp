
/* External memory control. Bit 7 holds the GBA-slot access rights: 0 gives the
   cartridge bus to the ARM9, 1 to the ARM7. */

#include "nitro/types.h"

#define REG_EXMEM_CNT (*(volatile u16 *)0x04000204)

void OSi_FreeCartridgeBus(void)
{
    REG_EXMEM_CNT |= 0x0080;
}
