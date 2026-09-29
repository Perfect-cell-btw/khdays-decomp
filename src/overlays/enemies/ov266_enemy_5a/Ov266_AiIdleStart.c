/* Unless the busy byte at *(child+4)+0xad is set, fire ov107_020c5af8(*child, 0x15e, 0xb,
 * *(child+8)), run ov266_020d0168, play the anim (ov107 mode 7,1) and register the handler. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void Ov266_ResetPoseCache(int a);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov266_IdleTick_2(int);
void Ov266_AiIdleStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_BuildAndSendUpdate(*(int *)child, 0x15e, 0xb, *(int *)(child + 8));
    Ov266_ResetPoseCache(child);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 7, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov266_IdleTick_2);
}
