/* Play the anim (ov107 mode 0x13), kick the secondary anim (ov107_020c9ee8 mode 6 on
 * *(child)+0x3ac), set the target rate (+0x14 = owner_rate*30/50), set +0x28 = 0x3000 and
 * register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_DashTick(int);
void Ov236_AiEnterDash(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x13, 0);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3ac), 6, 0);
    *(int *)(child + 0x14) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 50;
    *(int *)(child + 0x28) = 0x3000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_DashTick);
}
