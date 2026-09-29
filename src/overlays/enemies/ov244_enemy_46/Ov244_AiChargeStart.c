/* Unless the busy byte at *(child+0x30) is set, play the anim (ov107 mode 6), clear +0x1c and
 * the +9 byte and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov244_ChargeWindupTick(int);
void Ov244_AiChargeStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0x30) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 6, 0);
    *(int *)(child + 0x1c) = 0;
    *(signed char *)(child + 9) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov244_ChargeWindupTick);
}
