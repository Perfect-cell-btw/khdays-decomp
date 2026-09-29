/* Play the anim (ov107 mode 0,1), reset the timer (+0x44) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov255_DecideTick(int);
void Ov255_AiEnterDecide(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 1);
    *(int *)(child + 0x44) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov255_DecideTick);
}
