/* Ov245_Construct -- constructor of the ov245 actor: installs the handlers (+8 tick, +0xc
 * draw, +0x1c message, +0x30 / +0x34 callbacks, +0x24 hook, +0x1d0 hit), raises bits 1-3 and 6 of
 * the +0x60 high byte and bit 2 of +0x1ae, sets the +0x70 scale to 0.5, builds the primary item
 * from pool entry 0x11 of the +0x390 pool (+0x384, subscribed to +0x9c), the three +0x394 slot
 * items from entries 0x17..0x19 (attached, bit 1 of +0x5c), and a +0x22c placement (+0x388)
 * from the +0x64 pose with bit 1 of its +8 low byte; +0x38c starts empty. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);
struct w8 { unsigned int lo : 8, rest : 24; };
struct Ov245Slot { int pItem; int pad4; };
struct Ov245Self { char pad[0x394]; struct Ov245Slot slots[3]; };

extern void Ov245_ReleaseSubObjectsLoopThenNotify(void);
extern void Ov245_Child_TickSyncXform(void);
extern void Ov245_SlotSpawnMsg3(void);
extern void Ov245_Child_CreateAiTask(void);
extern void Ov245_ReleaseHeldObject(void);
extern void Ov245_FilterMessage(void);
extern void Ov245_SubHitFilter(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int *List_InsertSorted(void *list, int stride, int max);
extern int Ov107_CloneResourceTransform(void *pose);

void Ov245_Construct(int self) {
    int pool = *(int *)(self + 0x390);
    int i;
    int item;

    *(Callback *)(self + 0x8) = Ov245_ReleaseSubObjectsLoopThenNotify;
    *(Callback *)(self + 0xc) = Ov245_Child_TickSyncXform;
    *(Callback *)(self + 0x1c) = Ov245_SlotSpawnMsg3;
    *(Callback *)(self + 0x30) = Ov245_Child_CreateAiTask;
    *(Callback *)(self + 0x34) = Ov245_ReleaseHeldObject;
    *(Callback *)(self + 0x24) = Ov245_FilterMessage;
    *(Callback *)(self + 0x1d0) = Ov245_SubHitFilter;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 0x800;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 0x11));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    for (i = 0; i < 3; i++) {
        item = ((struct Ov245Self *)self)->slots[i].pItem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, i + 0x17));
        Ov107_EnqueueValue((char *)self, item);
        *(int *)(((struct Ov245Self *)self)->slots[i].pItem + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted((void *)(self + 0x22c), 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform((void *)(self + 0x64));
    ((struct w8 *)(*(int *)(self + 0x388) + 8))->lo |= 2;
    *(int *)(self + 0x38c) = 0;
}
