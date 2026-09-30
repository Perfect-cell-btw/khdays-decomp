/* Constructor of the ov219 enemy (twin of the ov220 constructor, sound 0x136): installs the handlers
 * (+8 tick, +0xc draw, +0x1c message, +0x30/+0x34 callbacks, +0x1d0 hit, +0x1dc finish,
 * +0x1d4/+0x1e0/+0x1e4 callbacks), seeds the +0x64 pose (scale 0x7cc, y 0x7cc), writes the
 * {-0x54f, 0, -0x625, 0x54e, 0xd34, 0x294} bounds at +0x1fc; builds the primary item from pool
 * entry 0 (+0x384, subscribed), keeps the named motion handle from pool entry 1 (+0x394), the
 * three sub-items listed by the overlay's 0x020d18a0 byte table into the inline slot table at
 * +0x3c4 (attached, bit 1), two placements on the +0x22c/+0x144 lists (+0x388/+0x38c) from the
 * +0x64 pose, then loads sound 0x136. Codegen: the box is spelled with the max corner derived
 * from the min corner (min.x - 0xd6, min.x + 0xa9d, min.y + 0xd34, min.z + 0x8b9), which is
 * what makes mwcc chain the constants from the one pool word; the slot store is chained
 * through `item` so the call result is stored before the copy. */

#include "nitro/types.h"

typedef void (*Callback)(void);
typedef struct { int w[6]; } Bounds;
typedef struct { u8 id[3]; } Kinds;
typedef struct { int pItem; int pad; } SubitemSlot;

extern void Ov219_ReleaseSubObjectsAndSlotArrayThenNotify(void);
extern void Ov219_ModelUpdateHook(void);
extern void Ov219_HandleMessage(void);
extern void Ov219_CreateNodeRegistryEntry(void);
extern void Ov219_ReleaseSubObjectsUnlessActive(void);
extern void Ov219_HandleHit(void);
extern void Ov219_Model_ReapplyTrack0(void);
extern void Ov219_RequestState3(void);
extern void Ov219_RequestSubState9IfNotCurrent(void);
extern void Ov219_TryBeginSubState10IfIdle(void);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int Ov107_CreateNamedResourceBinding(void *item, const char *name);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *pose);
extern void Res_RequestIdPair(int resourceId);
extern const Kinds data_ov219_020d18a0;
extern const char gOv219MoveName[];

void Ov219_Construct(char *self)
{
    Kinds kinds = data_ov219_020d18a0;
    Bounds bounds;
    const u8 *kind;
    int *slot;
    int item;
    int i;

    bounds.w[0] = -0x54f;
    bounds.w[1] = 0;
    bounds.w[2] = bounds.w[0] - 0xd6;
    bounds.w[3] = bounds.w[0] + 0xa9d;
    bounds.w[4] = bounds.w[1] + 0xd34;
    bounds.w[5] = bounds.w[2] + 0x8b9;
    *(Callback *)(self + 0x8) = Ov219_ReleaseSubObjectsAndSlotArrayThenNotify;
    *(Callback *)(self + 0xc) = Ov219_ModelUpdateHook;
    *(Callback *)(self + 0x1c) = Ov219_HandleMessage;
    *(Callback *)(self + 0x30) = Ov219_CreateNodeRegistryEntry;
    *(Callback *)(self + 0x34) = Ov219_ReleaseSubObjectsUnlessActive;
    *(Callback *)(self + 0x1d0) = Ov219_HandleHit;
    *(Callback *)(self + 0x1dc) = Ov219_Model_ReapplyTrack0;
    *(Callback *)(self + 0x1d4) = Ov219_RequestState3;
    *(Callback *)(self + 0x1e0) = Ov219_RequestSubState9IfNotCurrent;
    *(Callback *)(self + 0x1e4) = Ov219_TryBeginSubState10IfIdle;
    *(int *)(self + 0x70) = 0x7cc;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x7cc;
    *(int *)(self + 0x6c) = 0;
    *(Bounds *)(self + 0x1fc) = bounds;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    *(int *)(self + 0x394) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(self, 1), gOv219MoveName);
    kind = kinds.id;
    for (i = 0; i < 3; i++) {
        item = ((SubitemSlot *)(self + 0x3c4))[i].pItem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, *kind++));
        Ov107_EnqueueValue(self, item);
        *(int *)(item + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x38c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
    Res_RequestIdPair(0x136);
}
