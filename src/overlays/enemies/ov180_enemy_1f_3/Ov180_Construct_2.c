/* Constructor of the ov178 enemy (x3: ov178/179/180): installs the six handlers (+8 tick,
 * +0xc draw, +0x1c message, +0x30/+0x34 hit callbacks, +0x1dc finish), sets bits 1/2/3/6 of the
 * +0x60 high byte, bit 2 of the +0x1ae flags, the +0x70 latch, clears the two +0x54/+0x58
 * counters, raises bit 2 on the subscriber's +0x5c, then builds the model item from table
 * entry 3 of the +0x388 pool, subscribes it and clears its state. */

#include "nitro/types.h"

typedef void (*Callback)(void);

extern void Ov180_OnDespawn(void);
extern void Ov180_ConfigureSubObjectThenForward(void);
extern void Ov180_HandleMessage(void);
extern void Ov180_SpawnActorRegistryEntry(void);
extern void Ov180_ReleaseField38cUnlessState1ThenAdvance(void);
extern void Ov180_Model_ReapplyTracks(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int item, int a);

void Ov180_Construct_2(char *self)
{
    u16 hw;
    int pool = *(int *)(self + 0x388);
    *(Callback *)(self + 0x8) = Ov180_OnDespawn;
    *(Callback *)(self + 0xc) = Ov180_ConfigureSubObjectThenForward;
    *(Callback *)(self + 0x1c) = Ov180_HandleMessage;
    *(Callback *)(self + 0x30) = Ov180_SpawnActorRegistryEntry;
    *(Callback *)(self + 0x34) = Ov180_ReleaseField38cUnlessState1ThenAdvance;
    *(Callback *)(self + 0x1dc) = Ov180_Model_ReapplyTracks;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 1;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 3));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
}
