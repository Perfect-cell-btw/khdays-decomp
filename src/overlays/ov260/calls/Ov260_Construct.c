/* Constructor of the ov260 actor. +0x474 takes bit 2 of the game flags (0204c240, the alternate
 * voice); installs the handlers (+8, +0xc, +0x1c message, +0x30, +0x28, +0x2c, +0x34, +0x1d0, +0x1dc
 * set pose), sets +0x1c9 = 2, the +0x64 pose (scale 1.0) and the +0x1fc bounds. Builds the +0x384
 * body (kit 1 / 0x21 for the variant, else 0 / 0x20 with the +0x390 part), the hit volume (020cc078),
 * the +0x394 bank (clip 2), the +0x410 / +0x414 nodes, the +0x390 part (stance track, +0x424 tag
 * node), the +0x388 shell (0x22) and the +0x38c part (0x37, bit 2), the +0x428 part (0x23), the
 * twelve +0x478 hidden parts (kits of data_ov260_020d2a3c), two placements (+0x418 on the +0x22c
 * pool, +0x41c on the +0x144 pool), the +0x42c / +0x430 helpers and the fifteen +0x434 shards, and
 * loads sound bank 0x17c or 0x174. */
typedef unsigned char u8;
typedef void (*Callback)(void);
typedef struct { int id[12]; } PartKits;
typedef struct { int min[3]; int max[3]; } Bounds;
struct Parts { char pad[0x478]; struct { int obj; int pad; } part[12]; };
struct Ov260Shards { char pad[0x434]; int shards[15]; };

extern void Ov260_Actor_Destroy(void);
extern void Ov260_PropagateBlockChain(void);
extern void Ov260_ActorMessageHandler(void);
extern void Ov260_CreateAiTask(void);
extern void Ov260_AttachHook(void);
extern void Ov260_DetachHook(void);
extern void Ov260_Teardown(void);
extern void Ov260_OnHit(void);
extern void Ov260_SetPose(void);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern void Ov260_ArmModelCallback(char *self);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Snd_RegisterSeqAndBind(void *list, int b, void *c, int d);
extern void MainBlob_ResetSlotRows(int a, void *list);
extern int FindResourceIndexByName(int item, const char *name);
extern void SetSubitemState(int model, int track, int pose, int flag);
extern void RefreshObjectCallbacks(int item, int a);
extern int InsertSortedEntryWithKey(int item, int kind, void *name);
extern int Ov107_CreateNamedResourceBinding(void *item, void *name);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *placement);
extern int Ov260_New_3(char *self);
extern int Ov260_New_2(char *self);
extern int Ov260_New(char *self);
extern void Res_RequestIdPair(int resourceId);
extern u8 data_0204c240;
extern const PartKits data_ov260_020d2a3c;
extern char data_ov260_020d2aac[];
extern char data_ov260_020d2ab4[];
extern char data_ov260_020d2ac4[];
extern char data_ov260_020d2ac8[];

void Ov260_Construct(char *self)
{
    PartKits kits = data_ov260_020d2a3c;
    Bounds bounds;
    int i;
    int *slot;

    *(int *)(self + 0x474) = data_0204c240 & 4;
    bounds.min[0] = -0xeea;
    bounds.min[1] = 0x17;
    bounds.min[2] = -0x858;
    bounds.max[0] = bounds.min[0] + 0x1dd3;
    bounds.max[1] = bounds.min[1] + 0x1c27;
    bounds.max[2] = bounds.min[2] + 0xd64;
    *(Callback *)(self + 0x8) = Ov260_Actor_Destroy;
    *(Callback *)(self + 0xc) = Ov260_PropagateBlockChain;
    *(Callback *)(self + 0x1c) = Ov260_ActorMessageHandler;
    *(Callback *)(self + 0x30) = Ov260_CreateAiTask;
    *(Callback *)(self + 0x28) = Ov260_AttachHook;
    *(Callback *)(self + 0x2c) = Ov260_DetachHook;
    *(Callback *)(self + 0x34) = Ov260_Teardown;
    *(Callback *)(self + 0x1d0) = Ov260_OnHit;
    *(Callback *)(self + 0x1dc) = Ov260_SetPose;
    *(u8 *)(self + 0x1c9) = 2;
    *(int *)(self + 0x70) = 0x1000;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x1000;
    *(int *)(self + 0x6c) = 0;
    *(Bounds *)(self + 0x1fc) = bounds;
    if (*(int *)(self + 0x474) != 0) {
        *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 1));
        *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0x21));
    } else {
        *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
        *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0x20));
    }
    Ov260_ArmModelCallback(self);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    Snd_RegisterSeqAndBind(self + 0x394, *(int *)(*(int *)(self + 0x384) + 0x88), Ov107_PackTextureHandle(self, 2), 0xc);
    MainBlob_ResetSlotRows(*(int *)(self + 0x384), self + 0x394);
    *(int *)(self + 0x410) = FindResourceIndexByName(*(int *)(self + 0x384), data_ov260_020d2aac);
    *(int *)(self + 0x414) = FindResourceIndexByName(*(int *)(self + 0x384), data_ov260_020d2ab4);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x390));
    SetSubitemState(*(int *)(self + 0x390), 1, 0, 0);
    RefreshObjectCallbacks(*(int *)(self + 0x390), 0);
    *(int *)(self + 0x424) = InsertSortedEntryWithKey(*(int *)(self + 0x390), 3, data_ov260_020d2ac4);
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0x22));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x388));
    *(int *)(self + 0x38c) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0x37));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x38c));
    *(int *)(*(int *)(self + 0x38c) + 0x5c) |= 4;
    *(int *)(self + 0x428) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(self, 0x23), data_ov260_020d2ac8);
    for (i = 0; i < 12; i++) {
        ((struct Parts *)self)->part[i].obj = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, kits.id[i]));
        Ov107_EnqueueValue(self, ((struct Parts *)self)->part[i].obj);
        *(int *)(((struct Parts *)self)->part[i].obj + 0x5c) |= 2;
    }
    *(int *)(self + 0x418) = (int)List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x418) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x41c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x42c) = Ov260_New_3(self);
    *(int *)(self + 0x430) = Ov260_New_2(self);
    for (i = 0; i < 15; i++) {
        ((struct Ov260Shards *)self)->shards[i] = Ov260_New(self);
    }
    Res_RequestIdPair(*(int *)(self + 0x474) != 0 ? 0x17c : 0x174);
}
