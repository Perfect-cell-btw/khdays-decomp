/* Note that a peer acknowledged: raise that peer's bit in the mask at +0x8d9d,
 * skipping our own slot. Outside a live session there are no peers, so the
 * standalone flag at +0x8d9c is set instead. The sender's slot is the byte at
 * +1 of the message. */

#include "game/engine.h"

extern char *data_ov002_0207fa00;

void Ov002_NotePeerAck(char *message) {
    char *root = data_ov002_0207fa00;
    int slot;

    if (Session_IsReady() != 0) {
        slot = *(unsigned char *)(message + 1);

        if (slot == Session_GetLocalPlayerIndex()) {
            return;
        }

        *(unsigned char *)(root + 0x8d9d) |= 1 << slot;
        return;
    }

    *(unsigned char *)(root + 0x8d9c) = 1;
}
