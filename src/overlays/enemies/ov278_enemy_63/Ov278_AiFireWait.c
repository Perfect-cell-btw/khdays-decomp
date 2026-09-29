/* Unless the busy byte at *(child+0x24) is set, play the anim (ov107 mode 0xb,1) and dispatch
 * with no handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
void Ov278_AiFireWait(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0x24) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xb, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
