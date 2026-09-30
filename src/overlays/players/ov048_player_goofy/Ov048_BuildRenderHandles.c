/* Build step of the ov048 enemy (x4: ov048/067/086/103): clears the ready flags, requests
 * animation set 3, binds three render handles -- one against the scene link the enemy was
 * spawned from, two against the rig's own models at +0x2c38 and +0x2e78 -- clears the
 * 0xd5-byte work block at +0xda0, then latches the ready bits 0xf and returns them. */

#include "nitro/types.h"

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char *data_ov048_020b4b80;
extern char gOv048GoofyLiPackPath[];
extern char gOv048GoofyLiEa0PackPath[];
extern char gOv048GoofyLiEa1PackPath[];

u8 Ov048_BuildRenderHandles(char *self)
{
    char *rig = data_ov048_020b4b80 + 0x2c + 0x2c00;
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 3);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(gOv048GoofyLiPackPath, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    *(u8 **)(block + 0x344) = Ov022_AcquireGridSlot(gOv048GoofyLiEa0PackPath, *(u8 *)(self + 9), 1, rig + 0xc);
    *(u8 **)(block + 0x348) = Ov022_AcquireGridSlot(gOv048GoofyLiEa1PackPath, *(u8 *)(self + 9), 2, rig + 0x24c);
    Ov022_StepCueTrack(self + 0xda0, 0xd5);
    return *(u8 *)(block + 0x334) |= 0xf;
}
