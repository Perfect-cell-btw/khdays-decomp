/* Replay the ov146 actor's current armour animation: layers 0, 4, 1 and 2 of its +0x384 rig restart on
 * the +0x310 kind with the +0x311 loop bit and the rig pose resets. */

#include "nitro/types.h"

typedef struct { u8 b0 : 1; } Bit0;

extern void SetSubitemState(int rig, int channel, int a, int b);
extern void RefreshObjectCallbacks(int rig, int a);

void Ov146_ReplayArmourAnim(char *actor)
{
    SetSubitemState(*(int *)(actor + 0x384), 0, *(signed char *)(actor + 0x310), ((Bit0 *)(actor + 0x311))->b0);
    SetSubitemState(*(int *)(actor + 0x384), 4, *(signed char *)(actor + 0x310), ((Bit0 *)(actor + 0x311))->b0);
    SetSubitemState(*(int *)(actor + 0x384), 1, *(signed char *)(actor + 0x310), ((Bit0 *)(actor + 0x311))->b0);
    SetSubitemState(*(int *)(actor + 0x384), 2, *(signed char *)(actor + 0x310), ((Bit0 *)(actor + 0x311))->b0);
    RefreshObjectCallbacks(*(int *)(actor + 0x384), 0);
}
