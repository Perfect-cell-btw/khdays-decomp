/* Unless the busy byte at *(child+4)+0xad is set, stop the two secondary anims (ov107_020c5c14
 * on *(child)+0x3b4 and +0x3b8), set +0x24 = 0x1e000, mark sub-state 0xa and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
void Ov278_AiReleaseRidersOnAnimEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_SetStatusAndEmit(*(int *)(*(int *)child + 0x3b4), 0);
    Ov107_SetStatusAndEmit(*(int *)(*(int *)child + 0x3b8), 0);
    *(int *)(child + 0x24) = 0x1e000;
    *(signed char *)(*(int *)child + 0x1c7) = 0xa;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
