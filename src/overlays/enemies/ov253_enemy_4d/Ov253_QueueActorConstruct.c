/* Ov253_QueueActorConstruct -- queue actor construction: installs the handlers (+8 020d2388, +0xc
 * 020d23d8, +0x20 020d2474, +0x1c 020d24f8, +0x34 020d25e4, +0x30 020d283c, +0x1dc 020d26a8),
 * seeds the +0x54..+0x70 box, raises bits 2-4, 6 of the +0x60 high byte, bits 3-4 of +0x1ae and
 * 3, 7, 11 of +0x1b0, sets the four +0x38c scales to 1.0, builds the +0x384 item from pose
 * 0x1c of the +0x388 pool (subscribed to the +0x9c parent), the +0x3a0 ring object from pose
 * 0x27 (16 entries, drawn by 020d2058, owned here, bit 1 of +0x5c cleared) and its +0x3a4
 * transform, allocates the +0x3e8 pair block whose two effects come from the
 * data_ov253_020d49e0 poses (registered, bit 1 of +0x5c raised), links a +0x144 list slot to
 * the +0x64 pose as +0x3d4, clears the +0x3d8 latch and the queue counters (+0x3e0 sequence 1)
 * and allocates the 16-entry queue table cleared to -1. */
#include "nitro/types.h"
struct Ov253Entry { signed char a; signed char b; short c; };
struct Ov253Queue { char pad[0x3dc]; signed char count; signed char head; signed char tail; char pad3df; short seq; char pad3e2[2]; struct Ov253Entry *table; };
struct Ov253Poses { int w[2]; };
struct Ov253Pair { int pEffect; int pChild; };

extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int JointModel_New(void *item, int count);
extern void Ov107_EnqueueValue(char *self, int item);
extern void SrtTransform_SetIdentity(void *srt);
extern void *CallocInstance(int size);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const int data_ov253_020d49e0;
extern void Ov253_QueueActor_Destroy(void);
extern void Ov253_PlaceMounted(void);
extern void Ov253_SendSlotsMsg(void);
extern void Ov253_MsgHookB(void);
extern void Ov253_QueueSubStateTick(void);
extern void Ov253_CreateRegistryEntryAndLink_3(void);
extern void Ov253_ForwardAnimEvent(void);
extern void Ov253_DrawRing(void);

void Ov253_QueueActorConstruct(char *self) {
    struct Ov253Poses poses = *(const struct Ov253Poses *)((const char *)&data_ov253_020d49e0 + 4);
    int i;
    int *p;

    *(void **)(self + 0x8) = Ov253_QueueActor_Destroy;
    *(void **)(self + 0xc) = Ov253_PlaceMounted;
    *(void **)(self + 0x20) = Ov253_SendSlotsMsg;
    *(void **)(self + 0x1c) = Ov253_MsgHookB;
    *(void **)(self + 0x34) = Ov253_QueueSubStateTick;
    *(void **)(self + 0x30) = Ov253_CreateRegistryEntryAndLink_3;
    *(void **)(self + 0x1dc) = Ov253_ForwardAnimEvent;
    /* overwritten first: the dead store is dropped after scheduling but spends the block's
     * scheduling budget (keeps the ROM's unhoisted add further down) */
    *(int *)(self + 0x54) = 0x1000;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0x1000;
    *(int *)(self + 0x70) = 0x4000;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x4000;
    *(int *)(self + 0x6c) = 0;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x5c) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 0x18;
    *(u16 *)(self + 0x100 + 0xb0) |= 0x888;
    *(int *)(self + 0x38c) = 0x1000;
    *(int *)(self + 0x390) = 0x1000;
    *(int *)(self + 0x394) = 0x1000;
    *(int *)(self + 0x398) = 0x1000;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x388), 0x1c));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    *(int *)(self + 0x3a0) = JointModel_New(Ov107_PackTextureHandle(*(int *)(self + 0x388), 0x27), 0x10);
    Ov107_EnqueueValue(self, *(int *)(self + 0x3a0));
    *(void **)(*(int *)(self + 0x3a0) + 0x6c) = Ov253_DrawRing;
    *(char **)(*(int *)(self + 0x3a0) + 0x84) = self;
    *(int *)(*(int *)(self + 0x3a0) + 0x5c) &= ~2;
    SrtTransform_SetIdentity(self + 0x3a4);
    *(struct Ov253Pair **)(self + 0x3e8) = CallocInstance(0x10);
    for (i = 0; i < 2; i++) {
        (*(struct Ov253Pair **)(self + 0x3e8))[i].pEffect =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x388), poses.w[i]));
        Ov107_EnqueueValue(self, (*(struct Ov253Pair **)(self + 0x3e8))[i].pEffect);
        *(int *)((*(struct Ov253Pair **)(self + 0x3e8))[i].pEffect + 0x5c) |= 2;
    }
    p = List_InsertSorted(self + 0x144, 4, 0x64);
    *p = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x3d4) = *p;
    *(int *)(self + 0x3d8) = 0;
    ((struct Ov253Queue *)self)->count = 0;
    ((struct Ov253Queue *)self)->head = 0;
    ((struct Ov253Queue *)self)->tail = 0;
    ((struct Ov253Queue *)self)->seq = 1;
    ((struct Ov253Queue *)self)->table = CallocInstance(0x40);
    for (i = 0; i < 16; i++) {
        ((struct Ov253Queue *)self)->table[i].a = -1;
        ((struct Ov253Queue *)self)->table[i].b = -1;
        ((struct Ov253Queue *)self)->table[i].c = -1;
    }
}
