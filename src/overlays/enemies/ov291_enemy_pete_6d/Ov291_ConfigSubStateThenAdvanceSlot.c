/* AI step: posts pose 1, starts the action animation and continues with the path setup. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov291_stateTransformScaleTimer(void);

void Ov291_ConfigSubStateThenAdvanceSlot(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate((Actor *)(*state), 1, 0);
    Ov107_StartAnim(*(int *)(*state + 0x394), 0, 0);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov291_stateTransformScaleTimer);
}
