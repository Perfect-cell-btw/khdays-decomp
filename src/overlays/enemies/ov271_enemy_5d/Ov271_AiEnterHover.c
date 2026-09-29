/* Set the target rate (+0x60 = owner_rate*30/10), play the anim (ov107 mode 1,1), reset
 * the counter (+0x68) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov271_HoverTick(int);
void Ov271_AiEnterHover(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x60) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 1, 1);
    *(int *)(child + 0x68) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov271_HoverTick);
}
