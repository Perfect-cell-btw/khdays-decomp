/* Set anim (1 if child+0x78 else 3), set +0x5c = 0x1000, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov223_AiCooldownTick(void);
void Ov223_AiEnterCooldown(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), *(int *)(child + 0x78) != 0 ? 1 : 3, 0);
    *(int *)(child + 0x5c) = 0x1000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov223_AiCooldownTick);
}
