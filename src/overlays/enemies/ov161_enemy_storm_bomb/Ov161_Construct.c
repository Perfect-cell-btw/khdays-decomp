/* Ov161_Construct: ported from a matched sibling family (same shape, constants and offsets adjusted). */
struct v5 { int w[6]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov161_020cf260;
extern struct v3 data_02041dc8;
extern unsigned short gOv161BoneHimoName[];
extern unsigned short gOv161BoneHeadName[];
extern int gOv161MoveName;

extern void Ov161_Destroy(void), Ov161_TickWithChildRefresh(void), Ov161_TickAndPlaceBelowCamera(void);
extern void Ov161_HandleSpawnMessage(void), Ov161_SpawnActorRegistryEntry(void), Ov161_ReleaseTasks(void);
extern void Ov161_OnHit(void), Ov161_RequestSubState10IfIdleUnless7Or8(void), Ov161_Model_SetTrack0(void);

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

void Ov161_Construct(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov161_020cf260;
    *(void **)(param_1 + 8) = Ov161_Destroy;
    *(void **)(param_1 + 0xc) = Ov161_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov161_TickAndPlaceBelowCamera;
    *(void **)(param_1 + 0x1c) = Ov161_HandleSpawnMessage;
    *(void **)(param_1 + 0x30) = Ov161_SpawnActorRegistryEntry;
    *(void **)(param_1 + 0x34) = Ov161_ReleaseTasks;
    *(void **)(param_1 + 0x1d0) = Ov161_OnHit;
    *(void **)(param_1 + 0x1e0) = Ov161_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov161_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x1000;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x1000;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, gOv161BoneHimoName);
    *(void **)(param_1 + 0x3c0) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, gOv161BoneHeadName);
    *(void **)(param_1 + 0x3c8) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &gOv161MoveName);
    *(void **)(param_1 + 0x3c4) = CallocInstance(0x30);
    for (i = 0; i < 6; i++) {
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
    Res_RequestIdPair(0x152);
}
