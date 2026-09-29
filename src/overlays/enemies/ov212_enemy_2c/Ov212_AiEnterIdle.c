/* Play the anim (ov107 mode 6), reset the timer (+0x40) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov212_AiIdleStart(int);
void Ov212_AiEnterIdle(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 6, 0);
    *(int *)(child + 0x40) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov212_AiIdleStart);
}
