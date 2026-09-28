/* Constructor of the ov153 enemy (x3: ov153/154/155): installs the handlers (+8 tick, +0xc
 * draw, +0x1c message, +0x30 hit callback, +0x1d0 finish), sets bits 1/2/3/6 of the +0x60 high
 * byte, bit 2 of the +0x1ae flags, clears the +0x54 counter, sets the +0x70 scale to 0xa00 and
 * raises bit 2 on the subscriber's +0x5c. The model item comes from pool entry 4 (scaled to
 * 1.25 at its +4 placement, subscribed, its four channels bound with (0, 1), state cleared), the
 * two sub-items from the pool entries of the local table into a fresh 16-byte slot table
 * (+0x390, attached, bit 1 on their +0x5c), and the +0x388 list node gets a placement built from
 * the actor's +0x64 pose with bit 1 raised on its +8 flags (cf. Ov191_Construct_2). */
#include "nitro/types.h"
typedef void (*Callback)(void);

struct Ov153SubitemSlot {
    int pItem;
    int pad4;
};

struct bf {
    unsigned b : 8;
};

extern void Ov154_Actor_DestroyWithParts(void);
extern void Ov154_TickAndSyncModelXform(void);
extern void Ov154_AiState_OnMessage(void);
extern void Ov154_BroadcastPositionMessage(void);
extern void Ov154_CreateRegistryEntryAndLink(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern void Srt_SetScaleUniform(void *placement, int scale);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void *CallocInstance(int size);
extern void Ov107_EnqueueValue(char *self, int item);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const int data_ov154_020d1c60[2];

void Ov154_Construct(char *self)
{
    int kinds[2];
    u16 hw;
    int i;
    kinds[0] = data_ov154_020d1c60[0];
    kinds[1] = data_ov154_020d1c60[1];
    *(Callback *)(self + 0x8) = Ov154_Actor_DestroyWithParts;
    *(Callback *)(self + 0xc) = Ov154_TickAndSyncModelXform;
    *(Callback *)(self + 0x1c) = Ov154_AiState_OnMessage;
    *(Callback *)(self + 0x30) = Ov154_CreateRegistryEntryAndLink;
    *(Callback *)(self + 0x1d0) = Ov154_BroadcastPositionMessage;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x70) = 0xa00;
    i = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x38c), 4));
    Srt_SetScaleUniform((void *)(*(int *)(self + 0x384) + 4), 0x1400);
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 1, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 4, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(void **)(self + 0x390) = CallocInstance(0x10);
    for (; i < 2; i++) {
        (*(struct Ov153SubitemSlot **)(self + 0x390))[i].pItem =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(*(int *)(self + 0x38c), kinds[i]));
        Ov107_EnqueueValue(self, (*(struct Ov153SubitemSlot **)(self + 0x390))[i].pItem);
        *(int *)((*(struct Ov153SubitemSlot **)(self + 0x390))[i].pItem + 0x5c) |= 2;
    }
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct bf *)(*(int *)(self + 0x388) + 8))->b |= 2;
}
