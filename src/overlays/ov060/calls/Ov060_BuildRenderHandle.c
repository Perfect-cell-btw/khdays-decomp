/* Build step of the ov041 enemy (x4: ov041/060/080/097): clears the ready flags, requests
 * animation set 1, binds the render handle against the scene link the enemy was spawned from,
 * clears the 0xd7-byte work block at +0xda0, then latches the ready bits 9 and returns them. */
typedef unsigned char u8;

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char data_ov060_020b749c[];

u8 Ov060_BuildRenderHandle(char *self)
{
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 1);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(data_ov060_020b749c, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    Ov022_StepCueTrack(self + 0xda0, 0xd7);
    return *(u8 *)(block + 0x334) |= 9;
}
