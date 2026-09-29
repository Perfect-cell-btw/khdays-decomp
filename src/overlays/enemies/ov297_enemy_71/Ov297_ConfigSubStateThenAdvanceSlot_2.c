/* AI step: measures the target, counts the move, posts pose 7 and continues with picking the next
 * move. */

#include "game/enemy_common.h"

extern void Ov297_AcquireTargetGapAndAngle(int *node);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov297_AiPickNextMove(void);

void Ov297_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    Ov297_AcquireTargetGapAndAngle(node);
    state[0x1f]++;
    Ov107_PostTagUpdate((Actor *)(*state), 7, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov297_AiPickNextMove);
}
