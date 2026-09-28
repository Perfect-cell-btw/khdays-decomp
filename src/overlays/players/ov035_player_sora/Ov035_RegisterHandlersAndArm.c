/* Build step for the ov047 actor: clears the ready flags, requests animation set 2, binds two
 * render handles -- one against the scene link the actor was spawned from and one against the model
 * of the object it is attached to -- clears the 0xd3-byte work block at +0xda0, then latches the
 * three ready bits and returns them. */

typedef unsigned char u8;
typedef unsigned short u16;
struct GridEntry;
struct PartBlock { int header; u16 flags; };
struct Model { u8 pad00[0x28]; u16 flags; };
struct Attachment { u8 pad00[0x3c]; struct Model *model3c; };
struct BuildBlock {
    u8 pad000[0x334];
    u8 flags334;
    u8 pad335[0xb];
    struct GridEntry *entry340;
    struct GridEntry *entry344;
};
struct Runtime {
    u8 pad000[9];
    u8 slot09;
    u8 pad00a[0x16];
    struct PartBlock *part20;
    u8 pad024[0x22d4];
    struct BuildBlock block22f8;
    u8 pad2640[4];
    struct Attachment *attachment2644;
};
struct Path { char bytes[0x10]; };
extern const struct Path data_ov035_020b4c30;
extern const struct Path data_ov035_020b4c40;
extern void Ov022_ConfigureGridSlotMode(int id, int mode);
extern struct GridEntry *Ov022_AcquireGridSlot(const char *path, int id, int index, u16 *block);
extern int Ov022_StepCueTrack(u8 *p, int n);

u8 Ov035_RegisterHandlersAndArm(struct Runtime *self)
{
    struct BuildBlock *block = &self->block22f8;
    block->flags334 = 0;
    Ov022_ConfigureGridSlotMode(self->slot09, 2);
    block->entry340 = Ov022_AcquireGridSlot(data_ov035_020b4c30.bytes, self->slot09, 0, &self->part20->flags);
    block->entry344 = Ov022_AcquireGridSlot(data_ov035_020b4c40.bytes, self->slot09, 1, &self->attachment2644->model3c->flags);
    Ov022_StepCueTrack((u8 *)self + 0xda0, 0xd3);
    return block->flags334 |= 0xb;
}
