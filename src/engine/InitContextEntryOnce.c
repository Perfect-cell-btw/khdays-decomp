/* When the context is not yet running, resends the peer's queued messages and flips the entry's
 * double buffer. */

#include "game/engine.h"

extern int *gMsgQueue;

void InitContextEntryOnce(int param_1) {
    int *ctx = gMsgQueue;
    if (*ctx != 0) return;
    MsgQueue_ResendForPeer(param_1);
    Node_FlipDoubleBuffer(ctx[1] + param_1 * 0x20);
}
