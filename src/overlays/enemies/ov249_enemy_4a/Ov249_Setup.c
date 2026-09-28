/* Setup of the ov249 actor: installs the +8 tick (020d3f88), +0xc (020d3fac), +0x1c message (020d3fe4)
 * and +0x30 (020d408c) handlers, sets bits 1-3 of the +0x60 high byte and bits 2 and 4 of +0x1ae, the
 * +0x70 scale to 0.625 and clears +0x54/+0x58 and the +0x64 pose; the +0x9c body gets flag 2. The main
 * model (+0x384, pool item 0x24) is subscribed with actions 0/2/4/1 enabled, the +0x390 slot model
 * (kind from data_ov249_020d4988) attached and hidden, and the +0x388 contact built from the pose. */
typedef unsigned short u16;
typedef void (*Callback)(void);
typedef struct { int w[1]; } KindTable;
struct bf { unsigned b : 8; };

extern void Ov249_Destroy_2(void);
extern void Ov249_TickAndSyncModelXform(void);
extern void Ov249_ActorOnMessage(void);
extern void Ov249_CreateAiTask(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const KindTable data_ov249_020d4988;

void Ov249_Setup(char *self)
{
    int pool = *(int *)(self + 0x38c);
    KindTable kinds;
    u16 hw;

    kinds = data_ov249_020d4988;
    *(Callback *)(self + 0x8) = Ov249_Destroy_2;
    *(Callback *)(self + 0xc) = Ov249_TickAndSyncModelXform;
    *(Callback *)(self + 0x1c) = Ov249_ActorOnMessage;
    *(Callback *)(self + 0x30) = Ov249_CreateAiTask;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0xe) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 0x14;
    *(int *)(self + 0x70) = 0xa00;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x24));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 1, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, kinds.w[0]));
    Ov107_EnqueueValue(self, *(int *)(self + 0x390));
    *(int *)(*(int *)(self + 0x390) + 0x5c) |= 2;
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct bf *)(*(int *)(self + 0x388) + 8))->b |= 2;
}
