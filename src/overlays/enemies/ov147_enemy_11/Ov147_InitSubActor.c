/* Sub-actor initialiser: installs its callbacks and flags, binds the owner's textures to its two
 * child models, registers them and enqueues them with the shared framework. */

#include "nitro/types.h"
#include "game/engine.h"

struct ChildIds {
    int values[2];
};

struct Subitem {
    char pad00[0x5c];
    unsigned int flags5c;
};

struct PoolEntry {
    int value;
    int pad04;
    unsigned int flags : 8;
};

struct ChildSlot {
    struct Subitem *child;
    int pad04;
};

struct Obj {
    char pad00[0x08];
    void (*fn08)(void);
    void (*fn0c)(void);
    char pad10[0x0c];
    void (*fn1c)(void);
    char pad20[0x10];
    void (*fn30)(void);
    char pad34[0x2c];
    u16 flags60;
    char pad62[0x02];
    int camera[4];
    char pad74[0x28];
    struct Subitem *subscriber9c;
    char padA0[0x10e];
    u16 flags1ae;
    char pad1b0[0x20];
    void (*fn1d0)(void);
    char pad1d4[0x58];
    char pool22c[0x158];
    struct Subitem *subitem384;
    struct PoolEntry *poolEntry388;
    int field38c;
    struct Obj *owner390;
    struct ChildSlot slots394[2];
};

extern const struct ChildIds data_ov147_020ce8a8;
extern void Ov147_Destroy(void);
extern void Ov147_TickAndSyncModelXform(void);
extern void Ov147_PlaceNodeFromCommand(void);
extern void Ov147_CreateRegistryEntryAndLink(void);
extern void Ov147_Event_ReverseVelocityOnce(void);

extern void *Ov107_PackTextureHandle(struct Obj *owner, int index);
extern struct Subitem *CreateSubitemInstance0xB4(void *item);
extern void Ov107_EnqueueValue(struct Obj *self, struct Subitem *item);
extern int Ov107_CloneResourceTransform(void *camera);

void Ov147_InitSubActor(struct Obj *self)
{
    struct ChildIds ids = data_ov147_020ce8a8;
    struct Obj *owner = self->owner390;
    unsigned int flags;
    int i;

    self->fn08 = Ov147_Destroy;
    self->fn0c = Ov147_TickAndSyncModelXform;
    self->fn1c = Ov147_PlaceNodeFromCommand;
    self->fn30 = Ov147_CreateRegistryEntryAndLink;
    self->fn1d0 = Ov147_Event_ReverseVelocityOnce;

    flags = self->flags60;
    self->flags60 = flags & ~0xff00 |
        (((((flags << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    self->flags1ae |= 0x14;
    self->camera[3] = 0x600;

    self->subscriber9c->flags5c |= 4;

    self->subitem384 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 2));
    RegisterSubscriberSlot(self->subscriber9c, self->subitem384);
    SetSubitemState(self->subitem384, 0, 0, 1);
    SetSubitemState(self->subitem384, 2, 0, 1);
    SetSubitemState(self->subitem384, 4, 0, 1);
    SetSubitemState(self->subitem384, 1, 0, 1);
    RefreshObjectCallbacks(self->subitem384, 0);

    for (i = 0; i < 2; i++) {
        Ov107_EnqueueValue(
            self,
            self->slots394[i].child =
                CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, ids.values[i])));
        self->slots394[i].child->flags5c |= 2;
    }

    self->poolEntry388 = List_InsertSorted(self->pool22c, 0x10, 0x64);
    self->poolEntry388->value = Ov107_CloneResourceTransform(self->camera);
    self->poolEntry388->flags |= 2;
    self->field38c = 0;
}

