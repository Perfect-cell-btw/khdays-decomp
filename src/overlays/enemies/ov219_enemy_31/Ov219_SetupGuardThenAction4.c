/* State step: without a reachable target ends the step; otherwise posts pose 3, sends a state
 * update, clears the timer and hit flag and installs the chase-decision step. */

#include "game/enemy_common.h"

extern int Ov219_DistanceToTarget(void *node);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov219_ChaseDecision(void);

void Ov219_SetupGuardThenAction4(int *node) {
    int *state = (int *)node[1];
    if (Ov219_DistanceToTarget(node) < 0) {
        SetIndexedSlot(node, *(signed char *)(node + 8), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 3, 0);
    Ov107_BuildAndSendUpdate(*state, 0x136, 4, state[2]);
    state[5] = 0;
    *((char *)state + 0x3c) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov219_ChaseDecision);
}
