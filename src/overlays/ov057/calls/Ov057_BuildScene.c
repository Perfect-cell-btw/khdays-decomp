typedef unsigned char u8;

struct Ov057BuildBlock {
    char pad000[0x334];
    u8 flags334;
    char pad335[0x0b];
    u8 *handle340;
    u8 *handle344;
};

struct Ov057SceneLink { int field00; int field04; };

struct Ov057Actor {
    char pad000[9];
    u8 slot09;
    char pad00a[0x16];
    struct Ov057SceneLink *scene20;
    char pad024[0x22d4];
    struct Ov057BuildBlock buildBlock22f8;
};

struct Ov057SceneBlock { char pad000[0x11c]; int field11c; };
struct Ov057SceneBody { char pad0000[0x2c00]; struct Ov057SceneBlock block2c00; };
struct Ov057Scene { char pad000[0x2c]; struct Ov057SceneBody body2c; };


extern struct Ov057Scene *data_ov057_020b74a0;
extern char data_ov057_020b7410[];
extern char data_ov057_020b7420[];

extern void Ov022_ConfigureGridSlotMode(int slot, int mode);
extern u8 *Ov022_AcquireGridSlot(char *descriptor, int slot, int variant, void *parameters);
extern void Ov022_StepCueTrack(void *block, int size);

u8 Ov057_BuildScene(struct Ov057Actor *self)
{
    struct Ov057SceneBlock *scene;
    struct Ov057BuildBlock *block = &self->buildBlock22f8;

    block->flags334 = 0;
    Ov022_ConfigureGridSlotMode(self->slot09, 2);
    scene = &data_ov057_020b74a0->body2c.block2c00;
    block->handle340 = Ov022_AcquireGridSlot(
        data_ov057_020b7410, self->slot09, 0,
        &self->scene20->field04);
    block->handle344 = Ov022_AcquireGridSlot(
        data_ov057_020b7420, self->slot09, 1,
        &scene->field11c);
    Ov022_StepCueTrack((char *)self + 0xda0, 0xc8);
    return block->flags334 |= 0xb;
}
