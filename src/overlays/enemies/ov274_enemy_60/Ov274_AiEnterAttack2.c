/* Play the anim (ov107 mode 0xb), reset the timer (+0x24) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov274_FireAttack2OnIdle(int);
void Ov274_AiEnterAttack2(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xb, 0);
    *(int *)(child + 0x24) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov274_FireAttack2OnIdle);
}
