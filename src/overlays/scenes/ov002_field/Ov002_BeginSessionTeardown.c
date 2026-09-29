/* Raise the session's "leaving" flags once: bit 4 of the word at +0x8b64 and of
 * the byte at +0x8b68. Already-set (either 0x10 or 0x20) means the teardown is
 * under way and the call is ignored. Silences input, and in the boot mode gated
 * by bit 2 of data_0204c240 also stops the controller first. */

#include "game/engine.h"

extern char *data_ov002_0207fa00;
extern unsigned char data_0204c240;

void Ov002_BeginSessionTeardown(void) {
    char *root = data_ov002_0207fa00;
    int flags = *(int *)(root + 0x8b64);

    if ((flags & 0x30) != 0) {
        return;
    }

    *(int *)(root + 0x8b64) = flags | 0x10;
    *(unsigned char *)(root + 0x8b68) |= 0x10;

    if (data_0204c240 & 4) {
        PauseMenu_SetMode(0);
    }
    PauseMenu_SetAllowed(0);
}
