/* Constructor for the actor's sub-object: install the five entry points, set the
 * appearance flags, subscribe the main item, allocate the two child slots and
 * open the particle pool.
 *
 * The object itself is built by the allocator just above this one, which takes
 * 0x3a0 bytes and parks the owning actor at +0x398 -- so the slot pointer this
 * fills in at +0x39c is the object's very last word.
 *
 * Same template as the ov149 constructor, with this actor's flags nibble (0x40
 * rather than 0x46), its camera scale of 0x800, and the owner and slot pointers
 * moved from +0x38c/+0x390 to +0x398/+0x39c.
 */

#include "nitro/types.h"
#include "game/engine.h"

struct Ov142ChildIds {
    int values[2];
};

struct Ov142Subitem {
    char pad00[0x5c];
    unsigned int flags5c;
};

struct Ov142PoolEntry {
    int value;
    int pad04;
    unsigned int flags : 8;
};

struct Ov142ChildSlot {
    struct Ov142Subitem *child;
    int pad04;
};

struct Ov142SubObj {
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
    struct Ov142Subitem *subscriber9c;
    char padA0[0x10e];
    u16 flags1ae;
    char pad1b0[0x20];
    void (*fn1d0)(void);
    char pad1d4[0x58];
    char pool22c[0x158];
    struct Ov142Subitem *subitem384;
    struct Ov142PoolEntry *poolEntry388;
    char pad38c[0x0c];
    struct Ov142SubObj *owner398;
    struct Ov142ChildSlot *slots39c;
};

extern const struct Ov142ChildIds data_ov142_020d261c;
extern void Ov142_ReleaseSubObjectsListThenNotify(void);
extern void Ov142_TickAndSyncModelXform(void);
extern void Ov142_SpawnEffectForMsgSlotThenForward(void);
extern void Ov142_CreateRegistryEntryAndLink_2(void);
extern void Ov142_InvertVecOnceIfFlagSet(void);

extern void *Ov107_PackTextureHandle(struct Ov142SubObj *owner, int index);
extern struct Ov142Subitem *CreateSubitemInstance0xB4(void *item);
extern void *CallocInstance(int size);
extern void Ov107_EnqueueValue(struct Ov142SubObj *owner, struct Ov142Subitem *item);
extern int Ov107_CloneResourceTransform(void *camera);

void Ov142_InitializeSubObject(struct Ov142SubObj *self)
{
    struct Ov142ChildIds ids = data_ov142_020d261c;
    unsigned int flags;
    int i;

    self->fn08 = Ov142_ReleaseSubObjectsListThenNotify;
    self->fn0c = Ov142_TickAndSyncModelXform;
    self->fn1c = Ov142_SpawnEffectForMsgSlotThenForward;
    self->fn30 = Ov142_CreateRegistryEntryAndLink_2;
    self->fn1d0 = Ov142_InvertVecOnceIfFlagSet;

    self->flags1ae |= 4;
    self->camera[3] = 0x800;
    self->subscriber9c->flags5c |= 4;

    flags = self->flags60;
    self->flags60 = flags & ~0xff00 |
        (((((flags << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);

    self->subitem384 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self->owner398, 6));
    RegisterSubscriberSlot(self->subscriber9c, self->subitem384);
    SetSubitemState(self->subitem384, 0, 0, 1);
    SetSubitemState(self->subitem384, 2, 0, 1);
    RefreshObjectCallbacks(self->subitem384, 0);

    self->slots39c = CallocInstance(0x10);

    for (i = 0; i < 2; i++) {
        self->slots39c[i].child =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self->owner398, ids.values[i]));
        Ov107_EnqueueValue(self->owner398, self->slots39c[i].child);
        self->slots39c[i].child->flags5c |= 2;
    }

    self->poolEntry388 = List_InsertSorted(self->pool22c, 0x10, 0x64);
    self->poolEntry388->value = Ov107_CloneResourceTransform(self->camera);
    self->poolEntry388->flags |= 2;
}
