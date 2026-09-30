/* When the watched flag clears rolls the move timer and queues action 2. */

#include "game/engine.h"

extern int SetIndexedSlot();

void Ov182_AiRollTimerQueue2(unsigned char *obj) {
    unsigned char *mid = *(unsigned char **)(obj + 4);
    if (*(unsigned char *)(*(unsigned char **)(mid + 0xc)) != 0) {
        return;
    }
    {
        unsigned char *inner = *(unsigned char **)(mid + 0);
        int base = *(int *)(inner + 0x224);
        int diff = *(int *)(inner + 0x228) - base;
        if (diff < 0) diff = -diff;
        *(int *)(mid + 0x74) = base + RandNextScaled(diff + 1);
    }
    *(unsigned char *)(*(unsigned char **)(mid + 0) + 0x1c7) = 2;
    SetIndexedSlot(obj, *(signed char *)(obj + 0x20), 0);
}
