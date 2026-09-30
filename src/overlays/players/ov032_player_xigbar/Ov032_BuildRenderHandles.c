/* Build step of the ov032 enemy: clears the ready flags, requests animation set 3, binds three
 * render handles -- one against the scene link the enemy was spawned from, one against the
 * model of the attachment's part at +0x3c, one against the rig's own model at +0x2e84 -- clears
 * the 0xc5-byte work block at +0xda0, then latches the ready bits 0xf. Unlike the u8-returning
 * build steps of ov033-049 this one returns nothing; with a return value the argument setup
 * around the calls is scheduled differently. */

#include "nitro/types.h"

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char *data_ov032_020b58c0;
extern char gOv032XigbarLiPackPath[];
extern char gOv032XigbarLiEa0PackPath[];
extern char gOv032XigbarLiEa1PackPath[];

void Ov032_BuildRenderHandles(char *self)
{
    char *base = data_ov032_020b58c0;
    char *block = self + 0x2f8 + 0x2000;
    char *model;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 3);
    model = *(char **)(*(char **)(self + 0x2644) + 0x3c);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(gOv032XigbarLiPackPath, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    *(u8 **)(block + 0x344) = Ov022_AcquireGridSlot(gOv032XigbarLiEa0PackPath, *(u8 *)(self + 9), 1, model + 0x28);
    *(u8 **)(block + 0x348) = Ov022_AcquireGridSlot(gOv032XigbarLiEa1PackPath, *(u8 *)(self + 9), 2, base + 0x284 + 0x2c00);
    Ov022_StepCueTrack(self + 0xda0, 0xc5);
    *(u8 *)(block + 0x334) |= 0xf;
}
