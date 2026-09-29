/* Construction of the ov208 enemy's item (x3 with ov209/ov268): installs the handlers (+8
 * 020d393c, +0xc 020d3974, +0x1c 020d39d8, +0x20 020d3b40, +0x24 020d3ba8, +0x30 020d3d10, +0x34
 * 020d3bd4, +0x1dc 020d3c30), raises flags 0x4e in the +0x60 high byte and 0x14 in +0x1ae, sets
 * the +0x70 scale to 1.62, clears +0x54/+0x58 and raises bit 2 of the +0x9c body's +0x5c. The
 * +0x384 sub-item is built from pose 0x10 of the +0x394 owner, subscribed to +0x9c, reset (c7ac)
 * and its two set-3 bones resolved into +0x38c/+0x390; the four poses of data_ov209_020d662c
 * build the +0x398 pair table (registered, bit 1 of +0x5c), and the +0x22c collision handle
 * (+0x388) is reserved from the +0x64 pose with bit 1 of its flag byte raised. */

#include "nitro/types.h"
#include "game/engine.h"

struct PoseIds {
    int values[4];
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
    void (*fn20)(void);
    void (*fn24)(void);
    char pad28[0x08];
    void (*fn30)(void);
    void (*fn34)(void);
    char pad38[0x1c];
    int field54;
    int field58;
    char pad5c[0x04];
    u16 flags60;
    char pad62[0x02];
    int pose[4];
    char pad74[0x28];
    struct Subitem *subscriber9c;
    char padA0[0x10e];
    u16 flags1ae;
    char pad1b0[0x2c];
    void (*fn1dc)(void);
    char pad1e0[0x4c];
    char pool22c[0x158];
    struct Subitem *subitem384;
    struct PoolEntry *poolEntry388;
    int bone38c;
    int bone390;
    struct Obj *owner394;
    struct ChildSlot slots398[4];
};

extern const struct PoseIds data_ov209_020d662c;
extern const char data_ov209_020d669c[];
extern const char data_ov209_020d66a0[];
extern void Ov209_Destroy_2(void);
extern void Ov209_Projectile_TickSyncXform(void);
extern void Ov209_OnItemMessage(void);
extern void Ov209_SendMessage26(void);
extern void Ov209_LatchBitFlagTailTick(void);
extern void Ov209_SpawnActorRegistryEntry(void);
extern void Ov209_ReleaseTwoSubObjects(void);
extern void Ov209_Model_ReapplyTracks(void);

extern void *Ov107_PackTextureHandle(struct Obj *owner, int index);
extern struct Subitem *CreateSubitemInstance0xB4(void *item);
extern int InsertSortedEntryWithKey(struct Subitem *item, int set, const char *name);
extern void Ov107_EnqueueValue(struct Obj *self, struct Subitem *item);
extern int Ov107_CloneResourceTransform(void *pose);

void Ov209_ItemConstruct(struct Obj *self)
{
    struct PoseIds ids = data_ov209_020d662c;
    struct Obj *owner = self->owner394;
    unsigned int flags;
    int i;

    self->fn08 = Ov209_Destroy_2;
    self->fn0c = Ov209_Projectile_TickSyncXform;
    self->fn1c = Ov209_OnItemMessage;
    self->fn20 = Ov209_SendMessage26;
    self->fn24 = Ov209_LatchBitFlagTailTick;
    self->fn30 = Ov209_SpawnActorRegistryEntry;
    self->fn34 = Ov209_ReleaseTwoSubObjects;
    self->fn1dc = Ov209_Model_ReapplyTracks;

    flags = self->flags60;
    self->flags60 = flags & ~0xff00 |
        (((((flags << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    self->flags1ae |= 0x14;
    self->pose[3] = 0x19ec;
    self->field54 = 0;
    self->field58 = 0;

    self->subscriber9c->flags5c |= 4;

    self->subitem384 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 0x10));
    RegisterSubscriberSlot(self->subscriber9c, self->subitem384);
    RefreshObjectCallbacks(self->subitem384, 0);
    self->bone38c = InsertSortedEntryWithKey(self->subitem384, 3, data_ov209_020d669c);
    self->bone390 = InsertSortedEntryWithKey(self->subitem384, 3, data_ov209_020d66a0);

    for (i = 0; i < 4; i++) {
        Ov107_EnqueueValue(
            self,
            self->slots398[i].child =
                CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, ids.values[i])));
        self->slots398[i].child->flags5c |= 2;
    }

    self->poolEntry388 = (struct PoolEntry *)List_InsertSorted(self->pool22c, 0x10, 0x64);
    self->poolEntry388->value = Ov107_CloneResourceTransform(self->pose);
    self->poolEntry388->flags |= 2;
}
