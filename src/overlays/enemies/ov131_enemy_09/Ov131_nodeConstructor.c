/* Actor constructor: installs the class's callbacks, sets its camera pose, creates its model with
 * subitems and action resource, its five part instances and attach slots, and its transform
 * entries; requests its resource ids. */

#include "game/enemy_common.h"

struct v5 { int w[5]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov131_020cef58;
extern struct v3 data_02041dc8;
extern unsigned short data_ov131_020cefec[];
extern unsigned short data_ov131_020ceff8[];
extern int data_ov131_020cf004;

extern void Ov131_Destroy(void), Ov131_TickWithChildRefresh(void), Ov131_TickAndPlaceBelowCamera(void);
extern void Ov131_OnEffectMessage(void), Ov131_SpawnActorRegistryEntry(void), Ov131_ReleaseByStateAndSyncSrt(void);
extern void Ov131_ApplyHitAndRequestState(void), Ov131_RequestSubState10IfIdleUnless7Or8(void), Ov131_Model_SetTrack0(void);

extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void *CallocInstance();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov131_nodeConstructor(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov131_020cef58;
    *(void **)(param_1 + 8) = Ov131_Destroy;
    *(void **)(param_1 + 0xc) = Ov131_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov131_TickAndPlaceBelowCamera;
    *(void **)(param_1 + 0x1c) = Ov131_OnEffectMessage;
    *(void **)(param_1 + 0x30) = Ov131_SpawnActorRegistryEntry;
    *(void **)(param_1 + 0x34) = Ov131_ReleaseByStateAndSyncSrt;
    *(void **)(param_1 + 0x1d0) = Ov131_ApplyHitAndRequestState;
    *(void **)(param_1 + 0x1e0) = Ov131_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov131_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x800;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x800;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov131_020cefec);
    *(void **)(param_1 + 0x3c0) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov131_020ceff8);
    *(void **)(param_1 + 0x3c8) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle((char *)param_1, 1), &data_ov131_020cf004);
    *(void **)(param_1 + 0x3c4) = CallocInstance(0x28);
    for (i = 0; i < 5; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)param_1, tbl.w[i]));
        Ov107_EnqueueValue((char *)param_1, (int)(((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr));
        *(int *)((char *)((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x1000);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x1000);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x1000);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x1000);
    g.t = data_02041dc8;
    g.scale = 0x800;
    *(void **)(param_1 + 0x388) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x388) = (int)Ov107_CloneResourceTransform(&g);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        r = Ov107_CloneResourceTransform(&g);
        *p = (int)r;
        *(int *)(param_1 + 0x38c) = (int)r;
    }
    Res_RequestIdPair(0x119);
}
