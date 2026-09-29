/* Stop the anim (ov107 mode 0,0), clear flags 0x8e in the high byte at (*child)+0x60, set
 * bit 0 of the halfword at (*child)+0x1ae, seed the timer (+0x50=0xa000) and register the handler. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov210_AiStep_QueueAction2OnFlag0cClear(int);
struct node60_020d0c18 { unsigned short lo : 8; unsigned short hi : 8; };
void Ov210_AiEnterRecover(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0, 0);
    ((struct node60_020d0c18 *)(*(int *)child + 0x60))->hi &= ~0x8e;
    *(unsigned short *)(*(int *)child + 0x1ae) |= 1;
    *(int *)(child + 0x50) = 0xa000;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov210_AiStep_QueueAction2OnFlag0cClear);
}
