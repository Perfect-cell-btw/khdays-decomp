/* Roll a fresh 1..4 timer into (child)+0x50, then pose the actor per its phase byte at
 * (child)+0x5c (ov107 anim + local sub-pose), and register the handler. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov230_startAnim(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov230_AiPickStanceReaction(int);
void Ov230_RerollTimerThenDispatchSlot5c(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x50) = RandNextScaled(3) + 1;
    switch (*(int *)(child + 0x5c)) {
        case 0:
            Ov107_PostTagUpdate(*(int *)child, 2, 0);
            Ov230_startAnim(*(int *)child, 1);
            break;
        case 2:
            Ov107_PostTagUpdate(*(int *)child, 8, 0);
            Ov230_startAnim(*(int *)child, 6);
            break;
        case 3:
            Ov107_PostTagUpdate(*(int *)child, 5, 0);
            Ov230_startAnim(*(int *)child, 4);
            break;
        case 1:
            Ov107_PostTagUpdate(*(int *)child, 0xb, 0);
            Ov230_startAnim(*(int *)child, 8);
            break;
    }
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov230_AiPickStanceReaction);
}
