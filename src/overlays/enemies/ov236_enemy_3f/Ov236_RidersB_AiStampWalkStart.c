/* Unless the busy byte at *(child+0x20) is set, play the anim (ov107 mode 0xe,1), clear the
 * +0x7c byte and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov236_StampWalkTick(int);
void Ov236_RidersB_AiStampWalkStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0x20) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0xe, 1);
    *(signed char *)(child + 0x7c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov236_StampWalkTick);
}
