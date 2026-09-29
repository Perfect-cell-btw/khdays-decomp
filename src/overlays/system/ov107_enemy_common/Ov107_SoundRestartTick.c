/* Unless the object is inactive or locked, resolve the target via 02033d0c and dispatch. */

#include "game/enemy_common.h"

extern int Slot_Spawn(int a, int b, int c, int d);
extern int SetIndexedSlot(int, int, void *);
struct sb0 { int b0 : 1; };
void Ov107_SoundRestartTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int obj = *(int *)owner;
    if (((struct sb0 *)(obj + 0x40))->b0 == 0) return;
    if (*(unsigned char *)(obj + 0x1c4) & 2) return;
    *(int *)(owner + 0x10) = Slot_Spawn((short)*(short *)(owner + 4),
        *(unsigned char *)(owner + 6), *(int *)(owner + 0xc) + 0x10, 2);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov107_SoundFollowTick);
}
