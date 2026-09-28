/* Ov245_HopperConstruct -- constructor of the ov245 hopping actor: installs the handlers (+8 tick,
 * +0xc draw, +0x1c message, +0x30 / +0x34 callbacks, +0x24 hook, +0x1d0 hit), raises bits 1-3
 * and 6 of the +0x60 high byte and bit 2 of +0x1ae, sets the +0x70 scale to 1.0, raises bit 2 of
 * the +0x9c owner's +0x5c, builds the primary item from pool entry 0x1d of the +0x390 pool
 * (+0x384, subscribed, channels 0 and 4 started, motion halted), the three +0x394 slot items
 * from entries 0x1c / 0x1b / 0x25 (attached, bit 1 of +0x5c), and a +0x22c placement (+0x388)
 * from the +0x64 pose with bit 1 of its +8 low byte; +0x38c starts empty. */
typedef void (*Callback)(void);
#include "nitro/types.h"
struct w8 { unsigned int lo : 8, rest : 24; };
struct Ov245Slot { int pItem; int pad4; };
struct Ov245Self { char pad[0x394]; struct Ov245Slot slots[3]; };

extern void Ov245_ReleaseSubObjectsLoopThenNotify_2(void);
extern void Ov245_Hopper_TickSyncXform(void);
extern void Ov245_SlotSpawnMsg4(void);
extern void Ov245_CreateNodeRegistryEntry(void);
extern void Ov245_ReleaseHeld3a8(void);
extern void Ov245_FilterMessage(void);
extern void Ov245_HopToPartHitFilter(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int flag);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov107_EnqueueValue(int self, int item);
extern int *List_InsertSorted(void *list, int stride, int max);
extern int Ov107_CloneResourceTransform(void *pose);

struct PoolKinds { unsigned char id[3]; };
extern const struct PoolKinds data_ov245_020d71ac;   /* pool entries of the three slot items */

void Ov245_HopperConstruct(char *self) {   /* a byte pointer: int arithmetic on self schedules the handler stores differently */
    struct PoolKinds kinds = data_ov245_020d71ac;
    int pool = *(int *)(self + 0x390);
    int i;
    int item;
    const unsigned char *kind;

    *(Callback *)(self + 0x8) = Ov245_ReleaseSubObjectsLoopThenNotify_2;
    *(Callback *)(self + 0xc) = Ov245_Hopper_TickSyncXform;
    *(Callback *)(self + 0x1c) = Ov245_SlotSpawnMsg4;
    *(Callback *)(self + 0x30) = Ov245_CreateNodeRegistryEntry;
    *(Callback *)(self + 0x34) = Ov245_ReleaseHeld3a8;
    *(Callback *)(self + 0x24) = Ov245_FilterMessage;
    *(Callback *)(self + 0x1d0) = Ov245_HopToPartHitFilter;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 0x1000;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x1d));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    for (i = 0, kind = kinds.id; i < 3; i++) {
        item = ((struct Ov245Self *)self)->slots[i].pItem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, *kind++));
        Ov107_EnqueueValue(self, item);
        *(int *)(((struct Ov245Self *)self)->slots[i].pItem + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted((void *)(self + 0x22c), 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform((void *)(self + 0x64));
    ((struct w8 *)(*(int *)(self + 0x388) + 8))->lo |= 2;
    *(int *)(self + 0x38c) = 0;
}
