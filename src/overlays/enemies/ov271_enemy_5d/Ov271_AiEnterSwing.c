/* Set the target rate (+0x60 = owner_rate*30/10), play the anim (ov107 mode 3), set bit 3
 * of the halfword at (*child)+0x1ae and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov271_PublishSwing(int);
void Ov271_AiEnterSwing(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x60) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 10;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 3, 0);
    *(unsigned short *)(*(int *)child + 0x1ae) |= 8;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov271_PublishSwing);
}
