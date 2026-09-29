/* Play the anim (ov107 mode 1,1), reset the timer (+0x2c) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov268_AiIdleTimer(int);
void Ov268_AiEnterIdle(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 1, 1);
    *(int *)(child + 0x2c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov268_AiIdleTimer);
}
