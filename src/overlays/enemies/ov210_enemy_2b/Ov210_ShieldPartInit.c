/* Initialiser of the ov210 enemy's shield part: runs the base part setup (020c3c74), installs the +8,
 * +0xc, +0x1c, +0x20, +0x28 and +0x2c handlers, raises bit 2 of +0x40 and takes a fresh +0x3c group
 * (0203c400); the +0x64 pose takes 2/3 of the owner's (+0x18c) scale, bit 1 of the +0x60 high byte
 * is raised, and the +0x190 model (item 0x24 of the given pool, hidden flag) is subscribed to +0x9c
 * with actions 0/2/4/1 enabled. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);
struct Bit0 { unsigned int b0 : 1; };

extern void Ov210_Destroy_2(void);
extern void Ov210_ReaimEmitterCone(void);
extern void func_ov210_020d3f1c(void);   /* misnamed: an ov210 veneer (see ov223) */
extern void Ov210_SendBlankStatus(void);
extern void Ov210_RebuildSubObjectNotify(void);
extern void Ov210_FinishPendingRequest(void);
extern int ObjList_New(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);

void Ov210_ShieldPartInit(char *self, int pool)
{
    int scale;

    Ov107_InitActorNode((u16 *)self);
    *(Callback *)(self + 0x8) = Ov210_Destroy_2;
    *(Callback *)(self + 0xc) = Ov210_ReaimEmitterCone;
    *(Callback *)(self + 0x1c) = func_ov210_020d3f1c;
    *(Callback *)(self + 0x20) = Ov210_SendBlankStatus;
    *(Callback *)(self + 0x28) = Ov210_RebuildSubObjectNotify;
    *(Callback *)(self + 0x2c) = Ov210_FinishPendingRequest;
    *(int *)(self + 0x40) |= 4;
    *(int *)(self + 0x3c) = ObjList_New();
    scale = (int)(((long long)*(int *)(*(int *)(self + 0x18c) + 0x70) * 0xaaa + 0x800) >> 12);
    *(int *)(self + 0x70) = scale;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = scale;
    *(int *)(self + 0x6c) = 0;
    {
        u16 hw = *(u16 *)(self + 0x60);

        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 2) << 0x18) >> 0x10);
    }
    *(int *)(self + 0x190) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 0x24));
    ((struct Bit0 *)(*(int *)(self + 0x190) + 0x5c))->b0 = 1;
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x190));
    SetSubitemState(*(int *)(self + 0x190), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x190), 2, 0, 1);
    SetSubitemState(*(int *)(self + 0x190), 4, 0, 1);
    SetSubitemState(*(int *)(self + 0x190), 1, 0, 1);
}
