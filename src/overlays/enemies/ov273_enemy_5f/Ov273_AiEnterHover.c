/* Play the anim (ov107 mode 0,1), clear the +0x6a byte and the +0x70 field, register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov273_HoverTick(int);
void Ov273_AiEnterHover(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 1);
    *(signed char *)(child + 0x6a) = 0;
    *(int *)(child + 0x70) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov273_HoverTick);
}
