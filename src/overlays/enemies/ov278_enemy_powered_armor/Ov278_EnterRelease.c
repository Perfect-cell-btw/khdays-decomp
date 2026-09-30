/* Release entry: for each of the two children (+4 / +8) clear bit 1 of +0x5c, bind channel 0
 * with (0, 0), 1 with (0, 0), 2 with (0, 0) and 4 with (0, 0), then re-init it; the node moves to
 * 020d6094. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov278_EnterRecall(void);

void Ov278_EnterRelease(int *node) {
    int *state = (int *)node[1];
    int i;
    for (i = 0; i < 2; i++) {
        *(int *)(state[i + 1] + 0x5c) &= ~2;
        SetSubitemState((void *)state[i + 1], 0, 0, 0);
        SetSubitemState((void *)state[i + 1], 1, 0, 0);
        SetSubitemState((void *)state[i + 1], 2, 0, 0);
        SetSubitemState((void *)state[i + 1], 4, 0, 0);
        RefreshObjectCallbacks((void *)state[i + 1], 0);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov278_EnterRecall);
}
