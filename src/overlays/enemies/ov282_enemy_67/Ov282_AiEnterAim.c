/* Play the anim (ov107 mode 0xe), kick the secondary anim (ov107_020c9ee8 mode 3 on
 * *(child)+0x3b8), set +0x50 = 0x3000 and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov282_AimGiveUpOnFree(int);
void Ov282_AiEnterAim(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xe, 0);
    Ov107_StartAnim(*(int *)(*(int *)child + 0x3b8), 3, 0);
    *(int *)(child + 0x50) = 0x3000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov282_AimGiveUpOnFree);
}
