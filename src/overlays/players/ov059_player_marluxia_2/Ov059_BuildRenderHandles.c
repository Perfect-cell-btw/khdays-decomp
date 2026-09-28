/* Build step of the ov040 enemy (x4: ov040/059/079/096): clears the ready flags, requests
 * animation set 2, binds two render handles -- one against the scene link the enemy was spawned
 * from, one against the rig's own model at +0x2c5c -- clears the 0xce-byte work block at +0xda0,
 * then latches the ready bits 0xb and returns them. */

#include "nitro/types.h"

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char *data_ov059_020b7320;
extern char data_ov059_020b72b0[];
extern char data_ov059_020b72c0[];

u8 Ov059_BuildRenderHandles(char *self)
{
    char *rig = data_ov059_020b7320 + 0x2c50;
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 2);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(data_ov059_020b72b0, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    *(u8 **)(block + 0x344) = Ov022_AcquireGridSlot(data_ov059_020b72c0, *(u8 *)(self + 9), 1, rig + 0xc);
    Ov022_StepCueTrack(self + 0xda0, 0xce);
    return *(u8 *)(block + 0x334) |= 0xb;
}
