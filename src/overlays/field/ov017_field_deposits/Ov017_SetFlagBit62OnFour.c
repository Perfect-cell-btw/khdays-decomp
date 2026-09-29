/* Sets flag bit 62 on the four players' actors; returns 1. */

#include "game/engine.h"

int Ov017_SetFlagBit62OnFour(void) {
    int i;
    for (i = 0; i < 4; i++) {
        int *p = GetEntryField20ByIndex(i);
        if (p) {
            *(unsigned long long *)p |= 0x4000000000000000ULL;
        }
    }
    return 1;
}
