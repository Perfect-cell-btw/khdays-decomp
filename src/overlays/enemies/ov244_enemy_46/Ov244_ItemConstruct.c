/* Construction of the ov244 enemy's item (x2 with ov277): installs the handlers (+8 020cd64c,
 * +0xc 020cd68c, +0x1c 020cd6c4, +0x30 020cd7f8, +0x1d0 020cd7ac), raises flags 0x6e in the +0x60
 * high byte, 0xc in +0x1ae and bit 2 of the +0x9c body's +0x5c, sets the +0x70 scale to 0.625 and
 * +0x54 to 0x10. The +0x388 sub-item is built from pose 0x2f of the +0x384 owner, the +0xa0 pose
 * is scaled by 0.5 (ca9c), the sub-item is subscribed to +0x9c, its channels 0, 1, 2 and 4 are
 * enabled and it is reset (c7ac); the three poses of data_ov244_020d36d0 build the +0x3a4 pair
 * table (registered, bit 1 of +0x5c), and the +0x22c collision handle (+0x38c) is reserved from
 * the +0x64 pose with bit 1 of its flag byte raised. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct PoseIds {
    int values[3];
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
    char pad34[0x20];
    int field54;
    char pad58[0x08];
    u16 flags60;
    char pad62[0x02];
    int pose[4];
    char pad74[0x28];
    struct Subitem *subscriber9c;
    char srtA0[0x10e];
    u16 flags1ae;
    char pad1b0[0x20];
    void (*fn1d0)(void);
    char pad1d4[0x58];
    char pool22c[0x158];
    struct Obj *owner384;
    struct Subitem *subitem388;
    struct PoolEntry *poolEntry38c;
    char pad390[0x14];
    struct ChildSlot *slots3a4;
};

extern const struct PoseIds data_ov244_020d36d0;
extern void Ov244_Item_Destroy(void);
extern void Ov244_Item_TickSyncXform(void);
extern void Ov244_HandleRiderMessageA(void);
extern void Ov244_CreateRegistryEntryAndLink(void);
extern void Ov244_ActivateEntryIfFlagged(void);

extern struct Subitem *CreateSubitemInstance0xB4(void *item);
extern void Srt_SetScaleUniform(void *srt, int scale);
extern void RegisterSubscriberSlot(struct Subitem *subscriber, struct Subitem *item);
extern void SetSubitemState(struct Subitem *item, int state, int zero, int enabled);
extern void RefreshObjectCallbacks(struct Subitem *item, int value);
extern void *CallocInstance(int size);
extern struct PoolEntry *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *pose);

void Ov244_ItemConstruct(struct Obj *self)
{
    struct PoseIds ids = data_ov244_020d36d0;
    unsigned int flags;
    int i;

    self->fn08 = Ov244_Item_Destroy;
    self->fn0c = Ov244_Item_TickSyncXform;
    self->fn1c = Ov244_HandleRiderMessageA;
    self->fn30 = Ov244_CreateRegistryEntryAndLink;
    self->fn1d0 = Ov244_ActivateEntryIfFlagged;

    flags = self->flags60;
    self->flags60 = flags & ~0xff00 |
        (((((flags << 0x10) >> 0x18) | 0x6e) << 0x18) >> 0x10);
    self->flags1ae |= 0xc;
    self->subscriber9c->flags5c |= 4;
    self->pose[3] = 0xa00;
    self->field54 = 0x10;

    self->subitem388 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)self->owner384, 0x2f));
    Srt_SetScaleUniform(self->srtA0, 0x800);
    RegisterSubscriberSlot(self->subscriber9c, self->subitem388);
    SetSubitemState(self->subitem388, 0, 0, 1);
    SetSubitemState(self->subitem388, 1, 0, 1);
    SetSubitemState(self->subitem388, 2, 0, 1);
    SetSubitemState(self->subitem388, 4, 0, 1);
    RefreshObjectCallbacks(self->subitem388, 0);

    self->slots3a4 = CallocInstance(0x18);
    for (i = 0; i < 3; i++) {
        self->slots3a4[i].child = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)self->owner384, ids.values[i]));
        Ov107_EnqueueValue((char *)self, (int)self->slots3a4[i].child);
        self->slots3a4[i].child->flags5c |= 2;
    }

    self->poolEntry38c = List_InsertSorted(self->pool22c, 0x10, 0x64);
    self->poolEntry38c->value = Ov107_CloneResourceTransform(self->pose);
    self->poolEntry38c->flags |= 2;
}
