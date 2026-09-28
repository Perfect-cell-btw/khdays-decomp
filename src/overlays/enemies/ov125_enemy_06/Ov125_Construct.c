/* Constructor of the ov125 enemy. Installs the handlers (+8 release, +0xc draw veneer, +0x1c
 * message, +0x28/+0x2c/+0x30 callbacks, +0x34 leave, +0x1d0 hit, +0x1dc/+0x1e0 finish), sets
 * bit 6 of the +0x60 high byte, the +0x70 latch (0xe00), zeroes the +0x64 camera vector,
 * builds the model item from table entry 0 (subscribed, translated 0xe00 down) and resolves the
 * two anchor handles into +0x394/+0x398; then allocates the 9-entry effect set at +0x39c from
 * the table's ids (each attached and flagged), registers the four action slots (0/1/2/4) with
 * 0x2000, sets the blend of entries 2/3/4/8, creates the two pools at +0x388/+0x38c seeded with
 * the camera key, allocates the +0x390 projectile entry and the two +0x3a0 sub-entries, and
 * requests resource 0x11b. */
typedef struct { int id[9]; } IdTable;
typedef struct { int subitem; int pad; } Slot;
typedef struct { char pad[0x3a0]; int nodes[2]; } SubEntries;
#include "nitro/types.h"
typedef void (*Callback)(void);

extern void Ov125_Destroy(void);
extern void Ov125_TickAndSyncTwoModelXforms(void);
extern void Ov125_HandleMessage(void);
extern void Ov125_LeaveHandling(void);
extern void Ov125_ForwardRegionEventToParts(void);
extern void Ov125_NotifyPartsThenBase(void);
extern void Ov125_CreateAiTask(void);
extern void Ov125_RequestSubState9IfIdle(void);
extern void Ov125_OnHit(void);
extern void Ov125_Model_SetTrack0(void);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Srt_SetTranslationXYZ(void *srt, int x, int y, int z);
extern int InsertSortedEntryWithKey(int item, int kind, void *name);
extern int *CallocInstance(int size);
extern void Ov107_EnqueueValue(char *self, int item);
extern void Ov107_Actor_SetAttachSlot(char *self, int slot, int a, int b, int c);
extern void NNS_G3dMdlSetMdlPolygonIDAll(int anim, int blend);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *camera);
extern int *Ov125_SpawnProjectileEntry(char *self);
extern int Ov125_Actor_New(char *self);
extern void Res_RequestIdPair(int resourceId);
extern IdTable data_ov125_020d03a8;
extern char data_ov125_020d044c[];
extern char data_ov125_020d0454[];

void Ov125_Construct(char *self)
{
    IdTable ids = data_ov125_020d03a8;
    u16 hw;
    int i;
    int *slot;

    *(Callback *)(self + 0x8) = Ov125_Destroy;
    *(Callback *)(self + 0xc) = Ov125_TickAndSyncTwoModelXforms;
    *(Callback *)(self + 0x1c) = Ov125_HandleMessage;
    *(Callback *)(self + 0x34) = Ov125_LeaveHandling;
    *(Callback *)(self + 0x28) = Ov125_ForwardRegionEventToParts;
    *(Callback *)(self + 0x2c) = Ov125_NotifyPartsThenBase;
    *(Callback *)(self + 0x30) = Ov125_CreateAiTask;
    *(Callback *)(self + 0x1e0) = Ov125_RequestSubState9IfIdle;
    *(Callback *)(self + 0x1d0) = Ov125_OnHit;
    *(Callback *)(self + 0x1dc) = Ov125_Model_SetTrack0;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    *(int *)(self + 0x70) = 0xe00;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    Srt_SetTranslationXYZ((void *)(*(int *)(self + 0x384) + 4), 0, -0xe00, 0);
    *(int *)(self + 0x394) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov125_020d044c);
    *(int *)(self + 0x398) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov125_020d0454);
    *(int **)(self + 0x39c) = CallocInstance(0x48);
    for (i = 0; i < 9; i++) {
        (*(Slot **)(self + 0x39c))[i].subitem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, ids.id[i]));
        Ov107_EnqueueValue(self, (*(Slot **)(self + 0x39c))[i].subitem);
        *(int *)((*(Slot **)(self + 0x39c))[i].subitem + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(self, 0, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(self, 1, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(self, 2, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(self, 4, 1, 0, 0x2000);
    NNS_G3dMdlSetMdlPolygonIDAll(*(int *)(*(int *)((*(Slot **)(self + 0x39c))[2].subitem + 0x88) + 0x78), 0xa);
    NNS_G3dMdlSetMdlPolygonIDAll(*(int *)(*(int *)((*(Slot **)(self + 0x39c))[3].subitem + 0x88) + 0x78), 0xb);
    NNS_G3dMdlSetMdlPolygonIDAll(*(int *)(*(int *)((*(Slot **)(self + 0x39c))[4].subitem + 0x88) + 0x78), 0xa);
    NNS_G3dMdlSetMdlPolygonIDAll(*(int *)(*(int *)((*(Slot **)(self + 0x39c))[8].subitem + 0x88) + 0x78), 0xa);
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x38c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
    *(int **)(self + 0x390) = Ov125_SpawnProjectileEntry(self);
    for (i = 0; i < 2; i++) {
        ((SubEntries *)self)->nodes[i] = Ov125_Actor_New(self);
    }
    Res_RequestIdPair(0x11b);
}
