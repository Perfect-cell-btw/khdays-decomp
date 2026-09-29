/* Dispatches an event to the handler registered for this node's type (*node), if any. */

#include "game/enemy_common.h"

void Ov107_DispatchByType(unsigned short *node, int arg) {
    int handler = Ov107_FindMessageHandler(*node);
    if (handler == 0) {
        return;
    }
    Ov107_DispatchMessage((char *)handler, (unsigned char *)((int)node), arg);
}
