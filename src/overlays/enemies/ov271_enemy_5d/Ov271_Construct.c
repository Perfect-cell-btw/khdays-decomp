/* Constructor of the ov271 enemy. Installs the handlers (+8, +0xc draw, +0x1c
 * message, +0x28, +0x2c, +0x30, +0x34 update, +0x1d0 hit filter, +0x1dc, +0x1e0), copies the
 * data_ov271_020d3688 bounds box to +0x1fc, raises bit 6 of the +0x60 high byte, sets the +0x64
 * pose (scale 2.65), builds the +0x384 rig from pose 0 (subscribed to +0x9c, lowered by the same
 * 2.65) and resolves its two set-1 bones (+0x39c, +0x3a0); builds the four sub-items of
 * data_ov271_020d3678 into the +0x3a4 pair table (registered, bit 1 of +0x5c), registers actions
 * 0, 1, 2 and 4 with mode 1 (rate 3.0), builds the ten-joint +0x3a8 chain from pose 8, reserves
 * the +0x22c placement (+0x388) and one +0x144 placement (+0x38c) at the pose, creates the three
 * +0x390 parts (Ov271_BuildBeamState kinds 0/1/2) and loads sound 0x161. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);
typedef struct { int id[4]; } IdTable;
typedef struct { int w[6]; } Box;
typedef struct { int subitem; int pad; } Slot;

extern void Ov271_Destroy(void);
extern void Ov271_TickAndSyncTwoModelXforms(void);
extern void Ov271_OnEffectMessage(void);
extern void Ov271_PostTickCleanup(void);
extern void func_ov271_020d0458(void);
extern void func_ov271_020d0464(void);
extern void Ov271_CreateAiTask(void);
extern void Ov271_RequestSubState9IfNotCurrent(void);
extern void Ov271_HandleHit(void);
extern void Ov271_Model_ReapplyTrack0(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Srt_SetTranslationXYZ(void *srt, int x, int y, int z);
extern int InsertSortedEntryWithKey(int item, int kind, void *name);
extern int *CallocInstance(int size);
extern void Ov107_Actor_SetAttachSlot(char *self, int slot, int a, int b, int c);
extern int JointModel_New(void *res, int joints);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *camera);
extern int Ov271_BuildBeamState(char *self, int kind);
extern void Res_RequestIdPair(int resourceId);
extern IdTable data_ov271_020d3678;
extern Box data_ov271_020d3688;
extern char data_ov271_020d36ec[];
extern char data_ov271_020d36f4[];

void Ov271_Construct(char *self)
{
    IdTable ids = data_ov271_020d3678;
    u16 hw;
    int i;
    int *slot;

    *(Callback *)(self + 0x8) = Ov271_Destroy;
    *(Callback *)(self + 0xc) = Ov271_TickAndSyncTwoModelXforms;
    *(Callback *)(self + 0x1c) = Ov271_OnEffectMessage;
    *(Callback *)(self + 0x34) = Ov271_PostTickCleanup;
    *(Callback *)(self + 0x28) = func_ov271_020d0458;
    *(Callback *)(self + 0x2c) = func_ov271_020d0464;
    *(Callback *)(self + 0x30) = Ov271_CreateAiTask;
    *(Callback *)(self + 0x1e0) = Ov271_RequestSubState9IfNotCurrent;
    *(Callback *)(self + 0x1d0) = Ov271_HandleHit;
    *(Callback *)(self + 0x1dc) = Ov271_Model_ReapplyTrack0;
    *(Box *)(self + 0x1fc) = data_ov271_020d3688;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    *(int *)(self + 0x70) = 0x2a66;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    Srt_SetTranslationXYZ((void *)(*(int *)(self + 0x384) + 4), 0, -0x2a66, 0);
    *(int *)(self + 0x39c) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov271_020d36ec);
    *(int *)(self + 0x3a0) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov271_020d36f4);
    *(int **)(self + 0x3a4) = CallocInstance(0x20);
    for (i = 0; i < 4; i++) {
        (*(Slot **)(self + 0x3a4))[i].subitem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, ids.id[i]));
        Ov107_EnqueueValue(self, (*(Slot **)(self + 0x3a4))[i].subitem);
        *(int *)((*(Slot **)(self + 0x3a4))[i].subitem + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(self, 0, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(self, 1, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(self, 2, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(self, 4, 1, 0, 0x3000);
    *(int *)(self + 0x3a8) = JointModel_New(Ov107_PackTextureHandle(self, 8), 0xa);
    Ov107_EnqueueValue(self, *(int *)(self + 0x3a8));
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x38c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
    for (i = 0; i < 3; i++) {
        int kind = 0;
        switch (i) {
        case 0:
            kind = 0;
            break;
        case 2:
            kind = 2;
            break;
        case 1:
            kind = 1;
            break;
        }
        ((int *)(self + 0x390))[i] = Ov271_BuildBeamState(self, kind);
    }
    Res_RequestIdPair(0x161);
}
