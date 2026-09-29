/* Returns the setup context's halfword at +0x4c (0 without a context). */

#include "game/engine.h"

extern int data_ov022_020b2e78;
unsigned short func_ov022_02088cdc(void) {
    int p = ((int *)&data_ov022_020b2e78)[1];
    if (p != 0) return Mem_ReadU16((unsigned short *)(p + 0x4c));
    return 0;
}
