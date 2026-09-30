/* Ov203_Construct: ported from a matched sibling family (same shape, constants and offsets adjusted). */
struct v5 { int w[5]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov203_020d67d0;
extern struct v3 data_02041dc8;
extern unsigned short gOv203BoneHimoName[];
extern unsigned short gOv203BoneHeadName[];
extern int gOv203MoveName;

extern void Ov203_Destroy(void), Ov203_TickWithChildRefresh(void), Ov203_InitModelPose(void);
extern void Ov203_HandleSpawnMessage(void), Ov203_CreateRegistryEntryTwoCallbacks(void), Ov203_ReleaseTasks(void);
extern void Ov203_OnHit(void), Ov203_RequestSubState10IfIdleUnless7Or8(void), Ov203_Model_SetTrack0(void);

extern void *Ov107_PackTextureHandle(int obj, unsigned offset);
extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void *CallocInstance();
extern void Ov107_EnqueueValue();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov203_Construct(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov203_020d67d0;
    *(void **)(param_1 + 8) = Ov203_Destroy;
    *(void **)(param_1 + 0xc) = Ov203_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov203_InitModelPose;
    *(void **)(param_1 + 0x1c) = Ov203_HandleSpawnMessage;
    *(void **)(param_1 + 0x30) = Ov203_CreateRegistryEntryTwoCallbacks;
    *(void **)(param_1 + 0x34) = Ov203_ReleaseTasks;
    *(void **)(param_1 + 0x1d0) = Ov203_OnHit;
    *(void **)(param_1 + 0x1e0) = Ov203_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov203_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x1000;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x1000;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x3d4) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, gOv203BoneHimoName);
    *(void **)(param_1 + 0x3d8) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, gOv203BoneHeadName);
    *(void **)(param_1 + 0x388) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &gOv203MoveName);
    *(void **)(param_1 + 0x3dc) = CallocInstance(0x28);
    for (i = 0; i < 5; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3dc))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, tbl.w[i]));
        Ov107_EnqueueValue(param_1, ((struct slot *)*(int *)(param_1 + 0x3dc))[i].ptr);
        *(int *)((char *)((struct slot *)*(int *)(param_1 + 0x3dc))[i].ptr + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x3000);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x3000);
    g.t = data_02041dc8;
    g.scale = 0x1000;
    *(void **)(param_1 + 0x38c) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x38c) = (int)Ov107_CloneResourceTransform(&g);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        r = Ov107_CloneResourceTransform(&g);
        *p = (int)r;
        *(int *)(param_1 + 0x390) = (int)r;
    }
    Res_RequestIdPair(0x156);
}
