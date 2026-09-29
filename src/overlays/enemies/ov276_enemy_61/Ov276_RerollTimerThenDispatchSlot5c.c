/* Roll a fresh 1..4 timer into (child)+0x50, then pose the actor per its phase byte at (child)+0x5c
 * (ov107 anim + local sub-pose), and register the handler. */

#include "game/enemy_common.h"

extern int RandNextScaled(int max);
extern void Ov276_startAnim(int a, int b);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov276_AiPickStanceReaction(void);

void Ov276_RerollTimerThenDispatchSlot5c(int *node) {
    int *state = (int *)node[1];
    state[20] = RandNextScaled(3) + 1;
    switch (state[23]) {
    case 0:
        Ov107_PostTagUpdate((Actor *)(*state), 2, 0);
        Ov276_startAnim(*state, 1);
        break;
    case 2:
        Ov107_PostTagUpdate((Actor *)(*state), 8, 0);
        Ov276_startAnim(*state, 6);
        break;
    case 3:
        Ov107_PostTagUpdate((Actor *)(*state), 5, 0);
        Ov276_startAnim(*state, 4);
        break;
    case 1:
        Ov107_PostTagUpdate((Actor *)(*state), 0xb, 0);
        Ov276_startAnim(*state, 8);
        break;
    }
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov276_AiPickStanceReaction);
}
