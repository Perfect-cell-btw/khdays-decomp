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
typedef unsigned short u16;

struct Ov143ChildIds {
    int values[2];
};

struct Ov143Subitem {
    char pad00[0x5c];
    unsigned int flags5c;
};

struct Ov143PoolEntry {
    int value;
    int pad04;
    unsigned int flags : 8;
};

struct Ov143ChildSlot {
    struct Ov143Subitem *child;
    int pad04;
};

struct Ov143SubObj {
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
    struct Ov143Subitem *subscriber9c;
    char padA0[0x10e];
    u16 flags1ae;
    char pad1b0[0x20];
    void (*fn1d0)(void);
    char pad1d4[0x58];
    char pool22c[0x158];
    struct Ov143Subitem *subitem384;
    struct Ov143PoolEntry *poolEntry388;
    char pad38c[0x0c];
    struct Ov143SubObj *owner398;
    struct Ov143ChildSlot *slots39c;
};

extern const struct Ov143ChildIds data_ov143_020d625c;
extern void Ov143_ReleaseSubObjectsListThenNotify(void);
extern void Ov143_TickAndSyncModelXform(void);
extern void Ov143_SpawnEffectForMsgSlotThenForward(void);
extern void Ov143_CreateRegistryEntryAndLink_2(void);
extern void Ov143_InvertVecOnceIfFlagSet(void);

extern void *Ov107_PackTextureHandle(struct Ov143SubObj *owner, int index);
extern struct Ov143Subitem *CreateSubitemInstance0xB4(void *item);
extern void RegisterSubscriberSlot(struct Ov143Subitem *subscriber, struct Ov143Subitem *item);
extern void SetSubitemState(struct Ov143Subitem *item, int state, int zero, int enabled);
extern void RefreshObjectCallbacks(struct Ov143Subitem *item, int value);
extern void *CallocInstance(int size);
extern void Ov107_EnqueueValue(struct Ov143SubObj *owner, struct Ov143Subitem *item);
extern struct Ov143PoolEntry *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *camera);

void Ov143_InitializeSubObject(struct Ov143SubObj *self)
{
    struct Ov143ChildIds ids = data_ov143_020d625c;
    unsigned int flags;
    int i;

    self->fn08 = Ov143_ReleaseSubObjectsListThenNotify;
    self->fn0c = Ov143_TickAndSyncModelXform;
    self->fn1c = Ov143_SpawnEffectForMsgSlotThenForward;
    self->fn30 = Ov143_CreateRegistryEntryAndLink_2;
    self->fn1d0 = Ov143_InvertVecOnceIfFlagSet;

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
