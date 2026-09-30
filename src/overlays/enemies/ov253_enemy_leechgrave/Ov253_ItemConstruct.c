/* Ov253_ItemConstruct -- item construction: installs the handlers (+8 020d3c38, +0xc 020d3c78,
 * +0x1c 020d3cac, +0x30 020d3e3c, +0x1d0 020d3de0), raises bits 1-4, 6-7 of the +0x60 high byte,
 * bit 2 of +0x1ae and of the +0x9c parent's +0x5c, sets +0x70 / +0x54, builds the +0x384 item
 * from pose 0x23 of the +0x388 pool (subscribed to the parent, channels 0 and 2 enabled,
 * finalised), allocates the +0x398 pair block whose two effects come from the
 * data_ov253_020d4a00 poses (registered, bit 1 of +0x5c raised), and links a +0x144 list slot
 * to the +0x64 pose as +0x39c. */

#include "nitro/types.h"

struct Ov253Poses { int w[2]; };
struct Ov253Pair { int pEffect; int pChild; };

extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void *CallocInstance(int size);
extern void Ov107_EnqueueValue(int self, int item);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const struct Ov253Poses data_ov253_020d4a00;
extern void Ov253_ReleaseSubObjectsListThenNotify(void);
extern void Ov253_Item_TickSyncXform(void);
extern void Ov253_MsgHookC(void);
extern void Ov253_Item_CreateAiTask(void);
extern void Ov253_HitFilterFlip(void);

void Ov253_ItemConstruct(char *self) {
    struct Ov253Poses poses = data_ov253_020d4a00;
    int i;
    int *p;

    *(void **)(self + 0x8) = Ov253_ReleaseSubObjectsListThenNotify;
    *(void **)(self + 0xc) = Ov253_Item_TickSyncXform;
    *(void **)(self + 0x1c) = Ov253_MsgHookC;
    *(void **)(self + 0x30) = Ov253_Item_CreateAiTask;
    *(void **)(self + 0x1d0) = Ov253_HitFilterFlip;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0xde) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x70) = 0x200;
    *(int *)(self + 0x54) = 0x100;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x388), 0x23));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(struct Ov253Pair **)(self + 0x398) = CallocInstance(0x10);
    for (i = 0; i < 2; i++) {
        (*(struct Ov253Pair **)(self + 0x398))[i].pEffect =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x388), poses.w[i]));
        Ov107_EnqueueValue(*(int *)(self + 0x388), (*(struct Ov253Pair **)(self + 0x398))[i].pEffect);
        *(int *)((*(struct Ov253Pair **)(self + 0x398))[i].pEffect + 0x5c) |= 2;
    }
    p = List_InsertSorted(self + 0x144, 4, 0x64);
    *p = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x39c) = *p;
}
