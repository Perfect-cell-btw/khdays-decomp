/* Build step for the ov030 actor: clears the ready flags, requests animation set 2 for the actor's
 * slot, binds two render handles -- one against the scene link the actor was spawned from and one
 * against the shared scene block at the scene's +0x2ee4 -- clears the 0xd0 byte work block at
 * +0xda0, then latches the three ready bits and RETURNS them. Two things matter for reproducing it.
 * The return is the flags byte, so no instruction is spent materialising a result. And the scene
 * block pointer must be declared before the build block pointer: the other order gives the same
 * instructions with two registers swapped. */

#include "nitro/types.h"

struct Ov030BuildBlock {
    char pad000[0x334];
    u8 flags334;
    char pad335[0x0b];
    u8 *handle340;
    u8 *handle344;
};

struct Ov030SceneLink { int field00; int field04; };

struct Ov030Runtime {
    char pad000[9];
    u8 slot09;
    char pad00a[0x16];
    struct Ov030SceneLink *scene20;
    char pad024[0x22d4];
    struct Ov030BuildBlock buildBlock22f8;
};

struct Ov030SceneBlock { char pad000[0x234]; int field234; };
struct Ov030Scene { char pad0000[0x2cb0]; struct Ov030SceneBlock block2cb0; };
struct Ov030Descriptor { char bytes[0x10]; };

extern struct Ov030Scene *data_ov030_020b5a00;
extern struct Ov030Descriptor data_ov030_020b5960;
extern struct Ov030Descriptor data_ov030_020b5970;

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);

u8 Ov030_BuildActorHandles(struct Ov030Runtime *self)
{
    struct Ov030SceneBlock *scene = &data_ov030_020b5a00->block2cb0;
    struct Ov030BuildBlock *block = &self->buildBlock22f8;

    block->flags334 = 0;
    Ov022_ConfigureGridSlotMode(self->slot09, 2);
    block->handle340 = Ov022_AcquireGridSlot(
        data_ov030_020b5960.bytes, self->slot09, 0,
        &self->scene20->field04);
    block->handle344 = Ov022_AcquireGridSlot(
        data_ov030_020b5970.bytes, self->slot09, 1,
        &scene->field234);
    Ov022_StepCueTrack((char *)self + 0xda0, 0xd0);
    return block->flags334 |= 0xb;
}
