/* Constructor of the ov299 enemy: installs the handlers (+8 tick, +0xc draw, +0x1c message,
 * +0x30 hit callback, +0x1d0 callback), sets bits 1-4/6 of the +0x60 high byte and bit 2 of
 * +0x1ae, the +0x70 scale (0x800) and clears +0x54/+0x58; builds the primary item from entry 2
 * of the +0x390 pool (subscribed), the three +0x394 sub-items from the pool entries named by the
 * overlay's kind table (attached, bit 1), a shape on the +0x22c list (+0x388, bit 1) and clears
 * +0x38c. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct w8 { unsigned int lo : 8, rest : 24; };

struct Kinds3 { u8 a, b, c; };

struct Ov299Actor {
    char pad000[0x394];
    struct { int pItem; int nPad; } subitems[3];
};

extern void Ov299_ReleaseSubObjectsLoopThenNotify(void);
extern void Ov299_TickAndSyncModelXform(void);
extern void Ov299_HandleMessage(void);
extern void Ov299_BounceOnHit(void);
extern void Ov299_CreateRegistryEntryAndLink_2(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const struct Kinds3 data_ov299_020d4de8;

void Ov299_Construct(char *self)
{
    struct Kinds3 kinds;
    int pool;
    int i;
    int item;

    kinds = data_ov299_020d4de8;
    pool = *(int *)(self + 0x390);
    *(void **)(self + 0x8) = Ov299_ReleaseSubObjectsLoopThenNotify;
    *(void **)(self + 0xc) = Ov299_TickAndSyncModelXform;
    *(void **)(self + 0x1c) = Ov299_HandleMessage;
    *(void **)(self + 0x30) = Ov299_CreateRegistryEntryAndLink_2;
    *(void **)(self + 0x1d0) = Ov299_BounceOnHit;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x5e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 0x800;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 2));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    for (i = 0; i < 3; i++) {
        ((struct Ov299Actor *)self)->subitems[i].pItem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, ((u8 *)&kinds)[i]));
        Ov107_EnqueueValue((char *)((int)self), ((struct Ov299Actor *)self)->subitems[i].pItem);
        *(int *)(((struct Ov299Actor *)self)->subitems[i].pItem + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct w8 *)(*(int *)(self + 0x388) + 8))->lo |= 2;
    *(int *)(self + 0x38c) = 0;
}
