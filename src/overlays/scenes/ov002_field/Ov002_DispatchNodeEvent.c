#include "game/engine.h"

typedef int (*Ov002NodeHandler)(int pNode, int pEvent);

/* Forward the event to the node's registered handler, when the node is live
 * and the event still has work queued. Returns the handler's result, or 0. */
int Ov002_DispatchNodeEvent(int pNode, int pEvent)
{
    Ov002NodeHandler pfnHandler;
    int bLive;

    bLive = (GameState_GetField(*(unsigned short *)(pNode + 0x14),
                           *(unsigned char *)(pNode + 0x16)) & 1) != 0;
    if (bLive) {
        pfnHandler = *(Ov002NodeHandler *)(*(int *)(pNode + 8) + 0x1c);
        if (pfnHandler != 0) {
            if (*(int *)(pEvent + 0x10) > 0) {
                return pfnHandler(pNode, pEvent);
            }
        }
    }

    return 0;
}
