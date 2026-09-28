/* Actor constructor: installs the class's callbacks, sets its camera pose, creates its model with
 * subitems and child selector, its three part instances with attach slots, and its transform
 * entries; requests its resource ids. */

struct v5 { int w[3]; };
struct v3 { int a, b, c; };
struct slot { void *ptr; int pad; };

extern struct v5 data_ov136_020d39d8;
extern struct v3 data_02041dc8;
extern unsigned short data_ov136_020d3a58[];
extern unsigned short data_ov136_020d3a60[];
extern unsigned short data_ov136_020d3a64[];

extern void Ov136_Destroy(void), Ov136_ReleaseAndDestroy(void), Ov136_HandleSpawnMessage(void);
extern void Ov136_registryCreateEntry(void), Ov136_ReleaseSoundAndPublishPose(void), Ov136_OnHit(void);
extern void Ov136_RequestSubState9IfIdle(void), Ov136_Model_SetTrack0(void);
extern unsigned short data_ov136_020d3a4c[];

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

void Ov136_Construct(int param_1) {
    struct v5 tbl;
    struct { struct v3 t; int scale; } g;
    int i;
    tbl = data_ov136_020d39d8;
    *(void **)(param_1 + 8) = Ov136_Destroy;
    *(void **)(param_1 + 0xc) = Ov136_ReleaseAndDestroy;
    *(void **)(param_1 + 0x1c) = Ov136_HandleSpawnMessage;
    *(void **)(param_1 + 0x30) = Ov136_registryCreateEntry;
    *(void **)(param_1 + 0x34) = Ov136_ReleaseSoundAndPublishPose;
    *(void **)(param_1 + 0x1d0) = Ov136_OnHit;
    *(void **)(param_1 + 0x1e0) = Ov136_RequestSubState9IfIdle;
    *(void **)(param_1 + 0x1dc) = Ov136_Model_SetTrack0;
    *(int *)(param_1 + 0x70) = 0x800;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0x800;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    *(void **)(param_1 + 0x394) = InsertSortedEntryWithKey(*(int *)(param_1 + 0x384), 1, data_ov136_020d3a4c);
    *(void **)(param_1 + 0x3a0) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(param_1, 1), &data_ov136_020d3a58);
    *(void **)(param_1 + 0x3a4) = CallocInstance(0x18);
    for (i = 0; i < 3; i++) {
        ((struct slot *)*(int *)(param_1 + 0x3a4))[i].ptr = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, tbl.w[i]));
        Ov107_EnqueueValue(param_1, ((struct slot *)*(int *)(param_1 + 0x3a4))[i].ptr);
        *(int *)((char *)((struct slot *)*(int *)(param_1 + 0x3a4))[i].ptr + 0x5c) |= 2;
    }
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x1333);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x1333);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x1333);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x1333);
    *(void **)(param_1 + 0x398) = InsertSortedEntryWithKey((int)((struct slot *)*(int *)(param_1 + 0x3a4))[0].ptr, 1, data_ov136_020d3a60);
    *(void **)(param_1 + 0x39c) = InsertSortedEntryWithKey((int)((struct slot *)*(int *)(param_1 + 0x3a4))[0].ptr, 1, data_ov136_020d3a64);
    g.t = data_02041dc8;
    g.scale = 0x99a;
    *(void **)(param_1 + 0x38c) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x38c) = (int)Ov107_CloneResourceTransform(&g);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        *(int *)(param_1 + 0x390) = *p = (int)Ov107_CloneResourceTransform(&g);
    }
    Res_RequestIdPair(0x11c);
}
