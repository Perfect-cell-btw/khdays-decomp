/* Set bit 0 of the halfword at (*child)+0x1ae, play the anim (ov107 mode 7) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov275_Reaction_ChargeThenBreak(int);
void Ov275_AiEnterChargeBreak(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 7, 0);
    *(int *)(child + 0x24) = 0;
    *(signed char *)(child + 0x52) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov275_Reaction_ChargeThenBreak);
}
