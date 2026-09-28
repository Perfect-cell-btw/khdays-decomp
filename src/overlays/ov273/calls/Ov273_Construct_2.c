/* Constructor of the ov213 actor: installs the handlers (+8 tick, +0x20 hook, +0x1c message,
 * +0x30 callback, +0x1dc collision-set), sets the +0x70/+0x68 scales to 1/16 and clears the
 * +0x64/+0x6c/+0x58/+0x54 words, queues pose 2 at +0x1c9, raises bit 2 of the +0x9c list's
 * +0x5c word, flags 0x66 in the +0x60 high byte and bits 0x1d of +0x1ae, clears the two +0x218
 * halfwords, then builds the two collision items from pool entries 0x3f / 0x40 (+0x388 / +0x38c,
 * subscribed to +0x9c) and the +0x394 slot item from the data_ov273_020d6bb0 entry (attached,
 * bit 1 of its +0x5c). The pool entry is a one-word wrapper struct copied to the stack early
 * (the ROM's [sp] spill). */
typedef void (*Callback)(void);
typedef unsigned short u16;

extern void Ov273_Destroy_3(void);
extern void Ov273_SendMessage24_2(void);
extern void Ov273_CmdSpawnChildAtOffset(void);
extern void Ov273_CreateRegistryEntryForActor(void);
extern void Ov273_SelectCollisionSet(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Ov107_EnqueueValue(int self, int item);
struct Ov213PoolEntry { int index; };
extern const struct Ov213PoolEntry data_ov273_020d6bb0;

void Ov273_Construct_2(int self) {
    struct Ov213PoolEntry entry = data_ov273_020d6bb0;
    int item;

    *(Callback *)(self + 0x8) = Ov273_Destroy_3;
    *(Callback *)(self + 0x20) = Ov273_SendMessage24_2;
    *(Callback *)(self + 0x1c) = Ov273_CmdSpawnChildAtOffset;
    *(Callback *)(self + 0x30) = Ov273_CreateRegistryEntryForActor;
    *(Callback *)(self + 0x1dc) = Ov273_SelectCollisionSet;
    *(int *)(self + 0x70) = 0x100;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x100;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x54) = 0;
    *(unsigned char *)(self + 0x1c9) = 2;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x66) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 0x1d;
    *(u16 *)(self + 0x200 + 0x18) = 0;
    *(u16 *)(self + 0x200 + 0x1a) = 0;
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x384), 0x3f));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x388));
    *(int *)(self + 0x38c) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x384), 0x40));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x38c));
    item = *(int *)(self + 0x394) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x384), entry.index));
    Ov107_EnqueueValue(self, item);
    *(int *)(*(int *)(self + 0x394) + 0x5c) |= 2;
}
