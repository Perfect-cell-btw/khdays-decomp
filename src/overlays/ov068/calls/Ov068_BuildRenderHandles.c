/* Build step of the ov049 enemy (x4: ov049/068/087/104): clears the ready flags, requests
 * animation set 4, binds three render handles -- one against the scene link the enemy was
 * spawned from, one against the model of the object it is attached to, one against the rig's
 * own model at +0x2d00 -- clears the 0xd2-byte work block at +0xda0, then latches the ready
 * bits 0xf and returns them. */
typedef unsigned char u8;

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);
extern char *data_ov068_020b7500;
extern char data_ov068_020b74c0[];
extern char data_ov068_020b74d0[];
extern char data_ov068_020b74e4[];

u8 Ov068_BuildRenderHandles(char *self)
{
    char *rig = data_ov068_020b7500 + 0xfc + 0x2c00;
    char *block = self + 0x2f8 + 0x2000;

    block[0x334] = 0;
    Ov022_ConfigureGridSlotMode(*(u8 *)(self + 9), 4);
    *(u8 **)(block + 0x340) = Ov022_AcquireGridSlot(data_ov068_020b74c0, *(u8 *)(self + 9), 0, *(char **)(self + 0x20) + 4);
    *(u8 **)(block + 0x344) = Ov022_AcquireGridSlot(data_ov068_020b74d0, *(u8 *)(self + 9), 1, *(char **)(*(char **)(self + 0x2644) + 0xc) + 0x28);
    *(u8 **)(block + 0x348) = Ov022_AcquireGridSlot(data_ov068_020b74e4, *(u8 *)(self + 9), 2, rig + 4);
    Ov022_StepCueTrack(self + 0xda0, 0xd2);
    return *(u8 *)(block + 0x334) |= 0xf;
}
