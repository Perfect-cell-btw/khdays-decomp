/* Setup of the ov230 actor's companion: installs the +8 tick (020d5dd0), +0x1c message (020d5df4),
 * +0x30 (020d5f04) and +0x1dc (020d5e6c) handlers, sets bits 1-3 of the +0x60 high byte and bits 2 and
 * 4 of +0x1ae and the +0x64 pose (scale 0.5); the main model (+0x384, item 0x23 of the +0x388 pool) is
 * subscribed to +0x9c and the +0x38c slot model (kind from data_ov230_020d6464) attached and hidden. */
typedef unsigned short u16;
typedef void (*Callback)(void);
typedef struct { int w[1]; } KindTable;

extern void Ov230_Destroy_2(void);
extern void Ov230_HandleMessage(void);
extern void Ov230_CreateAiTask(void);
extern void Ov230_Model_ReapplyTracks(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov107_EnqueueValue(char *self, int item);
extern const KindTable data_ov230_020d6464;

void Ov230_CompanionSetup(char *self)
{
    int pool = *(int *)(self + 0x388);
    KindTable kinds;
    u16 hw;

    kinds = data_ov230_020d6464;
    *(Callback *)(self + 0x8) = Ov230_Destroy_2;
    *(Callback *)(self + 0x1c) = Ov230_HandleMessage;
    *(Callback *)(self + 0x30) = Ov230_CreateAiTask;
    *(Callback *)(self + 0x1dc) = Ov230_Model_ReapplyTracks;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0xe) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 0x14;
    *(int *)(self + 0x70) = 0x800;
    {
        int scale = *(int *)(self + 0x70);

        *(int *)(self + 0x64) = 0;
        *(int *)(self + 0x68) = scale;
        *(int *)(self + 0x6c) = 0;
    }
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x23));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x38c) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, kinds.w[0]));
    Ov107_EnqueueValue(self, *(int *)(self + 0x38c));
    *(int *)(*(int *)(self + 0x38c) + 0x5c) |= 2;
}
