/* Reads the input header halfword of the screen work area. Returns the halfword it reads. */

#include "game/engine.h"

extern int data_ov008_02090f04[];
unsigned short Ov008_ReadInputHeader(void)
{
    return Mem_ReadU16((void *)(data_ov008_02090f04[1] + 0x963e));
}
