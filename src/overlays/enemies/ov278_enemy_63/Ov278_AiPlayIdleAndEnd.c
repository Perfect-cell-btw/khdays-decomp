/* Play the anim (ov107 mode 0,1) on *child and dispatch (no handler). */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
void Ov278_AiPlayIdleAndEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
