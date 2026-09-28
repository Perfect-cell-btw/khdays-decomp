/* Constructor of the ov218 enemy (variant of the ov220 d1a24 one): installs the handlers (+8, +0xc,
 * +0x1c message, +0x30, +0x28, +0x2c, +0x34, +0x1d0 hit, +0x1dc, +0x1d4, +0x1e0, +0x1e4), the +0x64
 * pose (scale 0.49) and the +0x1fc bounds box; builds the +0x384 body (pose 0, set up by 020cc018,
 * subscribed to +0x9c) with its +0x3a8 bone, the +0x3ac bone of pose 1, the two +0x3dc slot models
 * (kinds of data_ov218_020cf30c) attached and hidden, the +0x388 / +0x38c placements from the pose,
 * the two +0x394 helpers (020ce040), and loads sound 0x135. */
typedef unsigned char u8;
typedef void (*Callback)(void);
typedef struct { int w[6]; } Bounds;
typedef struct { u8 id[2]; } Kinds;
typedef struct { int pItem; int pad; } SubitemSlot;

extern void Ov218_Actor_Destroy(void);
extern void Ov218_Update(void);
extern void Ov218_OnSetMessage(void);
extern void Ov218_Projectile_CreateAiTask(void);
extern void Ov218_ForwardRegionEventToParts(void);
extern void Ov218_NotifyPartsThenBase(void);
extern void Ov218_PostTickCleanup(void);
extern void Ov218_OnDamage(void);
extern void Ov218_Model_ReapplyTrack0(void);
extern void Ov218_RequestState3(void);
extern void Ov218_RequestSubState10IfNotCurrent(void);
extern void Ov218_RequestSubState11IfIdle(void);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int Ov107_CreateNamedResourceBinding(void *item, const char *name);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *pose);
extern void Res_RequestIdPair(int resourceId);
extern const Kinds data_ov218_020cf30c;
extern const char data_ov218_020cf32c[];
extern const char data_ov218_020cf338[];
extern int FindResourceIndexByName(int item, const char *name);
extern void Ov218_ArmModelCallback(char *self);
extern int Ov218_New(char *self);

void Ov218_Construct(char *self)
{
    Kinds kinds = data_ov218_020cf30c;
    Bounds bounds;
    const u8 *kind;
    int *slot;
    int item;
    int i;

    bounds.w[0] = -0x54f;
    bounds.w[1] = 0;
    bounds.w[2] = bounds.w[0] - 0xd6;
    bounds.w[3] = bounds.w[0] + 0xa9d;
    bounds.w[4] = bounds.w[1] + 0xd34;
    bounds.w[5] = bounds.w[2] + 0x8b9;
    *(Callback *)(self + 0x8) = Ov218_Actor_Destroy;
    *(Callback *)(self + 0xc) = Ov218_Update;
    *(Callback *)(self + 0x1c) = Ov218_OnSetMessage;
    *(Callback *)(self + 0x30) = Ov218_Projectile_CreateAiTask;
    *(Callback *)(self + 0x28) = Ov218_ForwardRegionEventToParts;
    *(Callback *)(self + 0x2c) = Ov218_NotifyPartsThenBase;
    *(Callback *)(self + 0x34) = Ov218_PostTickCleanup;
    *(Callback *)(self + 0x1d0) = Ov218_OnDamage;
    *(Callback *)(self + 0x1dc) = Ov218_Model_ReapplyTrack0;
    *(Callback *)(self + 0x1d4) = Ov218_RequestState3;
    *(Callback *)(self + 0x1e0) = Ov218_RequestSubState10IfNotCurrent;
    *(Callback *)(self + 0x1e4) = Ov218_RequestSubState11IfIdle;
    *(int *)(self + 0x70) = 0x7cc;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x7cc;
    *(int *)(self + 0x6c) = 0;
    *(Bounds *)(self + 0x1fc) = bounds;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
    Ov218_ArmModelCallback(self);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    *(int *)(self + 0x3a8) = FindResourceIndexByName(*(int *)(self + 0x384), data_ov218_020cf32c);
    *(int *)(self + 0x3ac) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(self, 1), data_ov218_020cf338);
    kind = kinds.id;
    for (i = 0; i < 2; i++) {
        item = ((SubitemSlot *)(self + 0x3dc))[i].pItem = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, *kind++));
        Ov107_EnqueueValue(self, item);
        *(int *)(item + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x38c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
    for (i = 0; i < 2; i++) {
        ((int *)(self + 0x394))[i] = Ov218_New(self);
    }
    Res_RequestIdPair(0x135);
}
