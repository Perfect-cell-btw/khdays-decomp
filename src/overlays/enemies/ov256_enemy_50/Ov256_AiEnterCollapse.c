/* Clear the 0x40 bit of the hw60 hi byte, kick anim 0x1a, restart sub-anim 020c9ee8, clear +0x4c,
 * latch sub-state 0xf and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov256_AiEnterCollapse(int param_1) {
    int owner = *(int *)(param_1 + 4);
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~0x40;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x1a, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 0xb, 0);
    *(int *)(owner + 0x4c) = 0;
    *(unsigned char *)(*(int *)owner + 0x1c7) = 0xf;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
