/* Recall entry: once both riders' +0xad bytes (+4 / +8 children) are clear, the two children
 * get their four channels (0, 1, 2, 4) bound with (1, 1) and the node moves to 020d615c. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov236_RecallWait(void);

void Ov236_EnterRecall(int *node) {
    int *state = (int *)node[1];
    int i;
    if (*(unsigned char *)(state[1] + 0xad) != 0) return;
    if (*(unsigned char *)(state[2] + 0xad) != 0) return;
    for (i = 0; i < 2; i++) {
        SetSubitemState((void *)state[i + 1], 0, 1, 1);
        SetSubitemState((void *)state[i + 1], 1, 1, 1);
        SetSubitemState((void *)state[i + 1], 2, 1, 1);
        SetSubitemState((void *)state[i + 1], 4, 1, 1);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov236_RecallWait);
}
