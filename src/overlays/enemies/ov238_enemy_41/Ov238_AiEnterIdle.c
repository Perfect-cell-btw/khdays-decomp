/* Clear +0x2d, kick the idle animation, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov238_IdleDecide(int);
void Ov238_AiEnterIdle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(signed char *)(owner + 0x2d) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_IdleDecide);
}
