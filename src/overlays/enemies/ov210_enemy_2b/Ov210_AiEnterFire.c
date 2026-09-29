/* Play the anim (ov107 mode 0xa) on *child and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov210_AiQueue2OnFlagClear(int);
void Ov210_AiEnterFire(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov210_AiQueue2OnFlagClear);
}
