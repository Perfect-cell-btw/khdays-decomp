/* Ov171_ConstructSubitem: sub-item constructor of the ov171 enemy (x2), variant of the matched ov175 sibling (four handlers, latch 0x64c). */

#include "nitro/types.h"

typedef struct {
    char pad_0000[0x5c];
    u32 flags_005c;
} Ov169Subitem;

typedef struct {
    int value;
    int pad_0004;
    u32 flags : 8;
} Ov169PoolEntry;

typedef struct {
    char pad_0000[0x08];
    void (*callback_0008)(void);
    void (*callback_000c)(void);
    char pad_0010[0x0c];
    void (*callback_001c)(void);
    char pad_0020[0x10];
    void (*callback_0030)(void);
    char pad_0034[0x20];
    int field_0054;
    int field_0058;
    char pad_005c[0x04];
    u16 flags_0060;
    char pad_0062[0x02];
    int field_0064;
    char pad_0068[0x08];
    int field_0070;
    char pad_0074[0x28];
    Ov169Subitem *subscriber_009c;
    char pad_00a0[0x10e];
    u16 flags_01ae;
    char pad_01b0[0x20];
    void (*callback_01d0)(void);
    char pad_01d4[0x58];
    char pool_022c[0x158];
    Ov169Subitem *subitem_0384;
    Ov169PoolEntry *poolEntry_0388;
    int owner_038c;
} Ov169Object;

extern void *Ov107_PackTextureHandle(int owner, int index);
extern Ov169Subitem *CreateSubitemInstance0xB4(void *item);
extern void RegisterSubscriberSlot(Ov169Subitem *subscriber, Ov169Subitem *item);
extern void SetSubitemState(Ov169Subitem *item, int state, int zero, int enabled);
extern void RefreshObjectCallbacks(Ov169Subitem *item, int value);
extern Ov169PoolEntry *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *field);
extern void Ov171_OnDespawn(void);
extern void Ov171_TickAndSyncModelXform(void);
extern void Ov171_CreateNodeRegistryEntry(void);
extern void Ov171_TryTriggerEffect(void);

void Ov171_ConstructSubitem(Ov169Object *self) {
    int owner = self->owner_038c;
    u16 v;

    self->callback_0008 = Ov171_OnDespawn;
    self->callback_000c = Ov171_TickAndSyncModelXform;
    self->callback_0030 = Ov171_CreateNodeRegistryEntry;
    self->callback_01d0 = Ov171_TryTriggerEffect;
    v = self->flags_0060;
    self->flags_0060 =
        (u16)((v & ~0xff00) | (((((u32)v << 0x10) >> 0x18 | 0x4e) << 0x18) >> 0x10));
    self->flags_01ae |= 4;
    self->field_0070 = 0x64c;
    self->field_0054 = 0;
    self->field_0058 = 0;
    self->subscriber_009c->flags_005c |= 4;
    self->subitem_0384 = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(owner, 3));
    RegisterSubscriberSlot(self->subscriber_009c, self->subitem_0384);
    SetSubitemState(self->subitem_0384, 0, 0, 1);
    SetSubitemState(self->subitem_0384, 2, 0, 1);
    SetSubitemState(self->subitem_0384, 4, 0, 1);
    SetSubitemState(self->subitem_0384, 1, 0, 1);
    RefreshObjectCallbacks(self->subitem_0384, 0);
    self->poolEntry_0388 = List_InsertSorted(self->pool_022c, 0x10, 100);
    self->poolEntry_0388->value = Ov107_CloneResourceTransform(&self->field_0064);
    self->poolEntry_0388->flags |= 2;
}
