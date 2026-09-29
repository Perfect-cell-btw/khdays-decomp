/* Play the anim (ov107 mode 0xb), set +0x50 = 0x3000, kick the secondary anim
 * (ov107_020c9ee8 on *(child)+0x3b8) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov282_RebuildSteerFireChild(int);
void Ov282_AiEnterSteerFire(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xb, 0);
    *(int *)(child + 0x50) = 0x3000;
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3b8), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov282_RebuildSteerFireChild);
}
