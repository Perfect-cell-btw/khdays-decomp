
/* External memory control. Bit 11 holds the NDS-slot access rights: 0 gives the
   card bus to the ARM9, 1 to the ARM7. */

#include "nitro/types.h"
#include "nitro/hw.h"

void OSi_FreeCardBus(void)
{
    REG_EXMEM_CNT |= 0x0800;
}
