/* Clears the embedded build flags, configures the graphics slot, opens the two ov077 resource paths
 * into variants 0 and 1, steps the actor cue track to 200, and marks the build state ready with
 * flags 0x0b. */

#include "nitro/types.h"

struct Ov077BuildBlock {
    char pad000[0x334];
    u8 flags334;
    char pad335[0x0b];
    u8 *handle340;
    u8 *handle344;
};

struct Ov077SceneLink { int field00; int field04; };

struct Ov077Runtime {
    char pad000[9];
    u8 slot09;
    char pad00a[0x16];
    struct Ov077SceneLink *scene20;
    char pad024[0x22d4];
    struct Ov077BuildBlock buildBlock22f8;
};

struct Ov077SceneBlock { char pad000[0x11c]; int field11c; };
struct Ov077SceneBody { char pad0000[0x2c00]; struct Ov077SceneBlock block2c00; };
struct Ov077Scene { char pad000[0x2c]; struct Ov077SceneBody body2c; };
struct Ov077Descriptor { char bytes[0x10]; };

extern struct Ov077Scene *data_ov077_020b9b80;
extern struct Ov077Descriptor gOv077LexaeusLiPackPath;
extern struct Ov077Descriptor gOv077LexaeusLiEa2PackPath;

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);

u8 Ov077_BuildScene(struct Ov077Runtime *self)
{
    struct Ov077SceneBlock *scene;
    struct Ov077BuildBlock *block = &self->buildBlock22f8;

    block->flags334 = 0;
    Ov022_ConfigureGridSlotMode(self->slot09, 2);
    scene = &data_ov077_020b9b80->body2c.block2c00;
    block->handle340 = Ov022_AcquireGridSlot(
        gOv077LexaeusLiPackPath.bytes, self->slot09, 0,
        &self->scene20->field04);
    block->handle344 = Ov022_AcquireGridSlot(
        gOv077LexaeusLiEa2PackPath.bytes, self->slot09, 1,
        &scene->field11c);
    Ov022_StepCueTrack((char *)self + 0xda0, 0xc8);
    return block->flags334 |= 0xb;
}
