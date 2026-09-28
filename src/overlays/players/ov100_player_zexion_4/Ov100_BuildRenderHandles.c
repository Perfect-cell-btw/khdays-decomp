/* Build step of the ov045 enemy (x4: ov045/064/083/100): clears the ready flags, requests
 * animation set 2, binds two render handles -- one against the model of the object the enemy is
 * attached to (+0x28 of the attachment's model), one against the scene link it was spawned from
 * -- clears the 0xc9-byte work block at +0xda0, then latches the ready bits 0xb and returns
 * them. */
#include "nitro/types.h"

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char data_ov100_020bc170[];
extern char data_ov100_020bc184[];

u8 Ov100_BuildRenderHandles(char *self)
{
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 2);
    *(u8 **)(block + 0x344) = Ov022_AcquireGridSlot(data_ov100_020bc170, *(u8 *)(self + 9), 0, *(char **)(*(char **)(self + 0x2644) + 0xc) + 0x28);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(data_ov100_020bc184, *(u8 *)(self + 9), 1, *(char **)(self + 0x20) + 4);
    Ov022_StepCueTrack(self + 0xda0, 0xc9);
    return *(u8 *)(block + 0x334) |= 0xb;
}
