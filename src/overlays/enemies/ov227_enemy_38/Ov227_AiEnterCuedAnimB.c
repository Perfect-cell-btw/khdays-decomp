/* Reset the child sprite (anim 0xf, clear +0x5c word and +0x75 flag), then
 * dispatch via SetIndexedSlot (handler Ov227_AiCuedAnimTickB). */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov227_AiCuedAnimTickB(void);
void Ov227_AiEnterCuedAnimB(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xf, 0);
    *(int *)(child + 0x5c) = 0;
    *(unsigned char *)(child + 0x75) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_AiCuedAnimTickB);
}
