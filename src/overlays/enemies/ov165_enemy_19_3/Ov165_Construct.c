/* Ov165_Construct: ported from a matched sibling family (same shape, constants and offsets adjusted). */
struct v5 { int w[5]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov165_020d4a94;
extern struct v3 data_02041dc8;
extern unsigned short data_ov165_020d4b2c[];
extern unsigned short data_ov165_020d4b38[];
extern int data_ov165_020d4b44;

extern void Ov165_Destroy(void), Ov165_TickWithChildRefresh(void), Ov165_InitModelPose(void);
extern void Ov165_HandleSpawnMessage(void), Ov165_SpawnActorRegistryEntry(void), Ov165_ReleaseTasks(void);
extern void Ov165_OnHit(void), Ov165_RequestSubState10IfIdleUnless7Or8(void), Ov165_Model_SetTrack0(void);

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

void Ov165_Construct(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov165_020d4a94;
    *(void **)(param_1 + 8) = Ov165_Destroy;
    *(void **)(param_1 + 0xc) = Ov165_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov165_InitModelPose;
    *(void **)(param_1 + 0x1c) = Ov165_HandleSpawnMessage;
    *(void **)(param_1 + 0x30) = Ov165_SpawnActorRegistryEntry;
    *(void **)(param_1 + 0x34) = Ov165_ReleaseTasks;
    *(void **)(param_1 + 0x1d0) = Ov165_OnHit;
    *(void **)(param_1 + 0x1e0) = Ov165_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov165_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x1000;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x1000;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov165_020d4b2c);
    *(void **)(param_1 + 0x3c0) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov165_020d4b38);
    *(void **)(param_1 + 0x3c8) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &data_ov165_020d4b44);
    *(void **)(param_1 + 0x3c4) = CallocInstance(0x28);
    for (i = 0; i < 5; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, tbl.w[i]));
        Ov107_EnqueueValue(param_1, ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr);
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
