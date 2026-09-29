/* Recall wait: unless the kind is 9, requires both riders' (+0x3b4 / +0x3b8) +0x1ac flag bit 1;
 * then the two children get channels 0 / 1 / 2 / 4 bound with (2, 0) and the node moves to
 * 020d6250. */

#include "game/engine.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov278_FinishWhenAnimsEnd(void);

void Ov278_RecallWait(int *node) {
    int *state = (int *)node[1];
    int both = 0;
    int actor = *state;
    int i;
    if ((*(unsigned short *)(*(int *)(actor + 0x3b4) + 0x100 + 0xac) & 2) != 0) {
        if ((*(unsigned short *)(*(int *)(actor + 0x3b8) + 0x100 + 0xac) & 2) != 0) {
            both = 1;
        }
    }
    if (*(signed char *)(actor + 0x100 + 0xc6) != 9) {
        if (both == 0) return;
    }
    for (i = 0; i < 2; i++) {
        SetSubitemState((void *)state[i + 1], 0, 2, 0);
        SetSubitemState((void *)state[i + 1], 1, 2, 0);
        SetSubitemState((void *)state[i + 1], 2, 2, 0);
        SetSubitemState((void *)state[i + 1], 4, 2, 0);
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov278_FinishWhenAnimsEnd);
}
