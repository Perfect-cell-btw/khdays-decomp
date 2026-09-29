/* Constructor of the ov262 enemy (byte-identical twin of ov261): raises bit 8 of the +0 flag
 * halfword, installs the handlers (+8 tick, +0xc draw, +0x34/+0x30/+0x10/+0x14/+0x38 callbacks,
 * +0x1dc finish), clears bit 2 of +0x40, raises bit 2 of the +0x9c parent's +0x5c, bit 6 of the
 * +0x60 high byte and bit 4 of +0x1ae, seeds the +0x64 pose (scale 0xa00, zero vector); builds the
 * primary item from pool entry 0 (+0x384, subscribed) and resolves the two named handles into
 * +0x390/+0x394, then two kind-1/2 sub-items (+0x388/+0x38c: subscribed, bit 0, channels 0 and 2
 * bound), a placement on the +0x144 list (+0x398) from the +0x64 pose, clears bit 0 of the +0x60
 * high byte, loads sound 0x179 and finally sends the +0x38 hook a 60-byte notice (+0x14 = 1, bit 16
 * of +0x18 clear, +0x2c..+0x34 zero, +0x38..+0x3b = -1) that is freed right after. */

#include "nitro/types.h"

typedef void (*Callback)(void);

struct Bit0 {
    unsigned bit0 : 1;
};
struct hw60 { unsigned short lo : 8, hi : 8; };

struct Notice {
    char pad00[0x14];
    int nKind;
    unsigned int uFlagsLo : 16;
    unsigned int uFlagsHi : 16;
    char pad1c[0x10];
    int a2c;
    int a30;
    int a34;
    signed char b38;
    signed char b39;
    signed char b3a;
    signed char b3b;
};

extern void Ov262_TeardownWithGuardedSlotNotify(void);
extern void Ov262_CopyBlockThenNotify(void);
extern void Ov262_TickHook(void);
extern void Ov262_CreateRegistryEntryAndLink(void);
extern void Ov262_RefreshAndCopyTwoBlocks(void);
extern void Ov262_GrabReleaseHook(void);
extern void Ov262_ReallocBufferInitConsts(void);
extern void Ov262_Model_SetTrack0(void);
extern void *Ov107_PackTextureHandle(char *self, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int InsertSortedEntryWithKey(int item, int kind, const char *name);
extern void SetSubitemState(int item, int channel, int a, int b);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *pose);
extern void Res_RequestIdPair(int resourceId);
extern struct Notice *CallocInstance(int size);
extern void FreeInstanceMemory(struct Notice *p);
extern const char data_ov262_020d51cc[];
extern const char data_ov262_020d51dc[];

void Ov262_EnemyConstruct(char *self)
{
    volatile int *p;
    struct Notice *notice;

    *(u16 *)self |= 0x100;
    /* the first handler is written five times: the repeats are dead stores the compiler drops
     * after scheduling, and they use up its scheduling budget so the rest of the constructor keeps
     * the ROM's order (the same lever as the repeated +0x60 clear in ov146) */
    *(Callback *)(self + 0x8) = Ov262_TeardownWithGuardedSlotNotify;
    *(Callback *)(self + 0x8) = Ov262_TeardownWithGuardedSlotNotify;
    *(Callback *)(self + 0x8) = Ov262_TeardownWithGuardedSlotNotify;
    *(Callback *)(self + 0x8) = Ov262_TeardownWithGuardedSlotNotify;
    *(Callback *)(self + 0x8) = Ov262_TeardownWithGuardedSlotNotify;
    *(Callback *)(self + 0xc) = Ov262_CopyBlockThenNotify;
    *(Callback *)(self + 0x34) = Ov262_TickHook;
    *(Callback *)(self + 0x30) = Ov262_CreateRegistryEntryAndLink;
    *(Callback *)(self + 0x10) = Ov262_RefreshAndCopyTwoBlocks;
    *(Callback *)(self + 0x14) = Ov262_GrabReleaseHook;
    *(Callback *)(self + 0x38) = Ov262_ReallocBufferInitConsts;
    *(Callback *)(self + 0x1dc) = Ov262_Model_SetTrack0;
    *(int *)(self + 0x40) &= ~4;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 0x10;
    *(int *)(self + 0x70) = 0xa00;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    *(int *)(self + 0x390) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov262_020d51cc);
    *(int *)(self + 0x394) = InsertSortedEntryWithKey(*(int *)(self + 0x384), 1, data_ov262_020d51dc);
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 1));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x388));
    ((struct Bit0 *)(*(int *)(self + 0x388) + 0x5c))->bit0 = 1;
    SetSubitemState(*(int *)(self + 0x388), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x388), 2, 0, 1);
    *(int *)(self + 0x38c) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 2));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x38c));
    ((struct Bit0 *)(*(int *)(self + 0x38c) + 0x5c))->bit0 = 1;
    SetSubitemState(*(int *)(self + 0x38c), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x38c), 2, 0, 1);
    p = List_InsertSorted(self + 0x144, 4, 100);
    *p = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x398) = *p;
    ((struct hw60 *)(self + 0x60))->hi &= ~1;
    Res_RequestIdPair(0x179);
    notice = CallocInstance(0x3c);
    notice->nKind = 1;
    notice->uFlagsLo = 0;
    notice->a2c = 0;
    notice->a30 = 0;
    notice->a34 = 0;
    notice->b38 = -1;
    notice->b39 = -1;
    notice->b3a = -1;
    notice->b3b = -1;
    if (*(void (**)(char *, int, struct Notice *))(self + 0x38) != 0) {
        (*(void (**)(char *, int, struct Notice *))(self + 0x38))(self, 0x3c, notice);
    }
    FreeInstanceMemory(notice);
}
