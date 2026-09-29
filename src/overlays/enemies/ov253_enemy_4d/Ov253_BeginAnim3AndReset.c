/* Kick anim 3, set bit 0 of the +0x3b4 status byte, clear +0x1c/+0x31/+0x32, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov253_HeadButtTick(int);
void Ov253_BeginAnim3AndReset(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 3, 0);
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3b4) + 8))->f |= 1;
    *(int *)(owner + 0x1c) = 0;
    *(signed char *)(owner + 0x31) = 0;
    *(signed char *)(owner + 0x32) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_HeadButtTick);
}
