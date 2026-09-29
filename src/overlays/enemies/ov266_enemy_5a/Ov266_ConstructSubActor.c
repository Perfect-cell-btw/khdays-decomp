/* Constructor of the ov266 sub-actor: installs the handlers (+8 tick, +0xc draw veneer, +0x1c
 * message, +0x30 callback, +0x1dc collision-set), flags 0x4e in the +0x60 high byte and bits
 * 0x14 of +0x1ae, sets the +0x70 latch to 0xc00 and clears +0x54/+0x58, raises bit 2 of the
 * +0x9c list's +0x5c word, builds the +0x384 item from pool entry 7 (subscribed to +0x9c, cleared)
 * and the +0x394 item from entry 8 of pool 0x22 (attached, bit 1 of its +0x5c, its +0x88
 * animation's channel 4 bound to the +0xe0 table), then allocates the +0x390 child (020d35fc)
 * and clears +0x388. Codegen: `self` must be a `char *` parameter -- with an `int` the stored
 * +0x394 value is forwarded into the attach call (`mov r1,r0`) and the handler pool loads
 * interleave differently; the ROM reloads +0x394. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);

extern void Ov266_Destroy(void);
extern void func_ov266_020d2a34(void);
extern void Ov266_ApplyTransformMessage(void);
extern void Ov266_CreateAiTask(void);
extern void Ov266_RearmEmitters(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int item, int a);
extern int JointModel_New(void *item, int index);
extern void BindAnimTrack(void *animation, int track, void *table, short mode);
extern int Ov266_CreateReactionTask(int self);

void Ov266_ConstructSubActor(char *self) {
    int pool = *(int *)(self + 0x38c);

    *(Callback *)(self + 0x8) = Ov266_Destroy;
    *(Callback *)(self + 0xc) = func_ov266_020d2a34;
    *(Callback *)(self + 0x1c) = Ov266_ApplyTransformMessage;
    *(Callback *)(self + 0x30) = Ov266_CreateAiTask;
    *(Callback *)(self + 0x1dc) = Ov266_RearmEmitters;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 0x14;
    *(int *)(self + 0x70) = 0xc00;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 7));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x394) = JointModel_New(Ov107_PackTextureHandle((char *)pool, 8), 0x22);
    Ov107_EnqueueValue((char *)((int)self), *(int *)(self + 0x394));
    *(int *)(*(int *)(self + 0x394) + 0x5c) |= 2;
    BindAnimTrack((void *)*(int *)(*(int *)(self + 0x394) + 0x88), 4, (char *)*(int *)(*(int *)(self + 0x394) + 0x88) + 0xe0, 0);
    *(int *)(self + 0x390) = Ov266_CreateReactionTask((int)self);
    *(int *)(self + 0x388) = 0;
}
