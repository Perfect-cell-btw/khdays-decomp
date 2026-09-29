/* Set anim (0x15 if child+0x78 else 0x16), clear +0x5c/+0x75/+0x76, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov225_SlamTick(void);
void Ov225_AiEnterAttackB(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), *(int *)(child + 0x78) != 0 ? 0x15 : 0x16, 0);
    *(int *)(child + 0x5c) = 0;
    *(unsigned char *)(child + 0x75) = 0;
    *(unsigned char *)(child + 0x76) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov225_SlamTick);
}
