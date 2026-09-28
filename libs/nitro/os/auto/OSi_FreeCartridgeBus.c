
/* External memory control. Bit 7 holds the GBA-slot access rights: 0 gives the
   cartridge bus to the ARM9, 1 to the ARM7. */

#include "nitro/types.h"
#include "nitro/hw.h"

void OSi_FreeCartridgeBus(void)
{
    REG_EXMEM_CNT |= 0x0080;
}
