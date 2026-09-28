/* Build step of the ov033 enemy (x4: ov033/051/071/089): clears the ready flags, requests
 * animation set 1, binds the render handle against the scene link the enemy was spawned from,
 * clears the 0xca-byte work block at +0xda0, then latches the ready bits 9 and returns them. */
#include "nitro/types.h"

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char data_ov033_020b4b3c[];

u8 Ov033_BuildRenderHandle(char *self)
{
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 1);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(data_ov033_020b4b3c, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    Ov022_StepCueTrack(self + 0xda0, 0xca);
    return *(u8 *)(block + 0x334) |= 9;
}
