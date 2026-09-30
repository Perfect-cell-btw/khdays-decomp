/* Returns the key-repeat bits, the setup context's halfword at +0x4c (0 without a context): a
 * key's bit on the frame it is pressed, then again every 3 to 4 frames once it has been held
 * some 15 frames. Ov022_UpdateCommandInput reads Down and Up there. */

#include "game/engine.h"

extern int data_ov022_020b2e78;
unsigned short Ov022_GetRepeatKeys(void) {
    int p = ((int *)&data_ov022_020b2e78)[1];
    if (p != 0) return Mem_ReadU16((unsigned short *)(p + 0x4c));
    return 0;
}
