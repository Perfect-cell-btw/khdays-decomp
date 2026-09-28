/* Actor constructor: installs the class's callbacks, sets its camera pose, creates its model with
 * subitems and action resource, its five part instances and attach slots, and its transform
 * entries; requests its resource ids. */

struct v5 { int w[5]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov132_020d0d78;
extern struct v3 data_02041dc8;
extern unsigned short data_ov132_020d0e0c[];
extern unsigned short data_ov132_020d0e18[];
extern int data_ov132_020d0e24;

extern void Ov132_Destroy(void), Ov132_TickWithChildRefresh(void), Ov132_TickAndPlaceBelowCamera(void);
extern void Ov132_OnEffectMessage(void), Ov132_SpawnActorRegistryEntry(void), Ov132_ReleaseByStateAndSyncSrt(void);
extern void Ov132_ApplyHitAndRequestState(void), Ov132_RequestSubState10IfIdleUnless7Or8(void), Ov132_Model_SetTrack0(void);

extern void *Ov107_PackTextureHandle();
extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void *CallocInstance();
extern void Ov107_EnqueueValue();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();
extern void Res_RequestIdPair();

void Ov132_nodeConstructor(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    long long r;
    tbl = data_ov132_020d0d78;
    *(void **)(param_1 + 8) = Ov132_Destroy;
    *(void **)(param_1 + 0xc) = Ov132_TickWithChildRefresh;
    *(void **)(param_1 + 0x10) = Ov132_TickAndPlaceBelowCamera;
    *(void **)(param_1 + 0x1c) = Ov132_OnEffectMessage;
    *(void **)(param_1 + 0x30) = Ov132_SpawnActorRegistryEntry;
    *(void **)(param_1 + 0x34) = Ov132_ReleaseByStateAndSyncSrt;
    *(void **)(param_1 + 0x1d0) = Ov132_ApplyHitAndRequestState;
    *(void **)(param_1 + 0x1e0) = Ov132_RequestSubState10IfIdleUnless7Or8;
    *(void **)(param_1 + 0x1dc) = Ov132_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x800;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x800;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x390) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov132_020d0e0c);
    *(void **)(param_1 + 0x3c0) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov132_020d0e18);
    *(void **)(param_1 + 0x3c8) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &data_ov132_020d0e24);
    *(void **)(param_1 + 0x3c4) = CallocInstance(0x28);
    for (i = 0; i < 5; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, tbl.w[i]));
        Ov107_EnqueueValue(param_1, ((struct slot *)*(int *)(param_1 + 0x3c4))[i].ptr);
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
    Res_RequestIdPair(0x119, (int)((unsigned long long)r >> 32));
}
