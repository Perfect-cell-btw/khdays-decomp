/* Ov164_Construct: ported from a matched sibling family (same shape, constants and offsets adjusted). */

#include "game/enemy_common.h"

struct v5 { int w[5]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov164_020d2c74;
extern struct v3 data_02041dc8;
extern unsigned short data_ov164_020d2d0c[];
extern unsigned short data_ov164_020d2d18[];
extern int data_ov164_020d2d24;

extern void Ov164_Destroy(void), Ov164_TickWithChildRefresh(void), Ov164_InitModelPose(void);
extern void Ov164_HandleSpawnMessage(void), Ov164_SpawnActorRegistryEntry(void), Ov164_ReleaseTasks(void);
extern void Ov164_OnHit(void), Ov164_RequestSubState10IfIdleUnless7Or8(void), Ov164_Model_SetTrack0(void);

extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void *CallocInstance();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov164_Construct(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov164_020d2c74;
    *(void **)(param_1 + 8) = Ov164_Destroy;
    *(void **)(param_1 + 0xc) = Ov164_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov164_InitModelPose;
    *(void **)(param_1 + 0x1c) = Ov164_HandleSpawnMessage;
    *(void **)(param_1 + 0x30) = Ov164_SpawnActorRegistryEntry;
    *(void **)(param_1 + 0x34) = Ov164_ReleaseTasks;
    *(void **)(param_1 + 0x1d0) = Ov164_OnHit;
    *(void **)(param_1 + 0x1e0) = Ov164_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov164_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x1000;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x1000;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov164_020d2d0c);
    *(void **)(param_1 + 0x3c0) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov164_020d2d18);
    *(void **)(param_1 + 0x3c8) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle((char *)param_1, 1), &data_ov164_020d2d24);
    *(void **)(param_1 + 0x3c4) = CallocInstance(0x28);
    for (i = 0; i < 5; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)param_1, tbl.w[i]));
        Ov107_EnqueueValue((char *)param_1, (int)(((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr));
        *(int *)((char *)((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x2000);
    g.t = data_02041dc8;
    g.scale = 0x1000;
    *(void **)(param_1 + 0x388) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x388) = (int)Ov107_CloneResourceTransform(&g);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        r = Ov107_CloneResourceTransform(&g);
        *p = (int)r;
        *(int *)(param_1 + 0x38c) = (int)r;
    }
    Res_RequestIdPair(0x153);
}
