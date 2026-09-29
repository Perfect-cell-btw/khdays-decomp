/* Set the target rate (+0x14 = owner_rate*30/50), play the anim (ov107 mode 0x15), kick the
 * secondary anim (ov107_020c9ee8 mode 8 on *(child)+0x3ac) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov278_LungeTick(int);
void Ov278_AiEnterLunge(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x14) = *(int *)(*(int *)param_1 + 0x2c) * 30 / 50;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x15, 0);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3ac), 8, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_LungeTick);
}
