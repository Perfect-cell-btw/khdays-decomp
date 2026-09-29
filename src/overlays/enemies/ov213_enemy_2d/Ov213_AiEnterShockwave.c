/* Clear +0x48, play the anim (ov107 mode 0xd), clear +0x1c / +0x68 / +0x69 / +0x60 and
 * register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov213_ShockwaveTick(int);
void Ov213_AiEnterShockwave(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x48) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xd, 0);
    *(int *)(child + 0x1c) = 0;
    *(signed char *)(child + 0x68) = 0;
    *(signed char *)(child + 0x69) = 0;
    *(int *)(child + 0x60) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov213_ShockwaveTick);
}
