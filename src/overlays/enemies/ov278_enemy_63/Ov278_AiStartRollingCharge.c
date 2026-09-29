/* Unless busy, kick anim (0xe, phase 1), clear +0x28, seed the pose and clear +0x4c, then dispatch. */

#include "game/enemy_common.h"

extern void MI_CpuFill8(void *dst, int val, int size);
extern int SetIndexedSlot(int, int, void *);
extern int data_02041dc8;
extern int Ov278_RollingChargeTick(int);
struct w3 { int a, b, c; };
void Ov278_AiStartRollingCharge(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xe, 1);
    *(int *)(owner + 0x28) = 0;
    *(struct w3 *)(owner + 0x3c) = *(struct w3 *)&data_02041dc8;
    MI_CpuFill8((void *)(owner + 0x4c), 0, 4);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov278_RollingChargeTick);
}
