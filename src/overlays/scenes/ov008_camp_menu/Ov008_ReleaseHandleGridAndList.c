/* Releases the 3x40 handle grid and every node of the list (DispatchByNodeKind on each), freeing
 * the nodes. */

#include "game/engine.h"

extern int NNS_FndRemoveListObject();
extern int NNS_FndGetNextListObject();
extern int NNSi_FndFreeFromDefaultHeap();

void Ov008_ReleaseHandleGridAndList(int unused, int **a, int *b) {
    int i, j;
    int *cur;
    int *next;

    if (a != 0) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 0x28; j++) {
                if (a[j] != 0) {
                    DispatchByNodeKind(&a[j]);
                }
            }
            a += 0x28;
        }
    }

    if (b == 0) {
        return;
    }

    cur = (int *)NNS_FndGetNextListObject(b, 0);
    if (cur == 0) {
        return;
    }

    for (;;) {
        next = (int *)NNS_FndGetNextListObject(b, cur);
        NNS_FndRemoveListObject(b, cur);
        DispatchByNodeKind(cur + 9);
        if (cur != 0) {
            NNSi_FndFreeFromDefaultHeap(cur);
        }
        cur = next;
        if (next == 0) {
            return;
        }
    }
}
