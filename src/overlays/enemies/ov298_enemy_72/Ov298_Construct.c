/* Constructor of the ov298 enemy (and its byte-identical twin): installs the handlers (+8 tick,
 * +0xc draw, +0x1c message, +0x30/+0x38 callbacks, +0x28/+0x2c veneers, +0x1d0 hit, +0x1dc
 * animation switch), sets +0x1c9 to 2, bit 9 of +0x1ae, the +0x64 pose (scale 0x1000, y 0x1000)
 * and the +0x1fc bounding box; builds the pool entry 0/1 items (+0x384/+0x388, subscribed), the
 * sub-item of the pool entry selected by the overlay's +0x54e8 variant (+0x39c, attached, bit
 * 1), two placements on the +0x22c/+0x144 lists (+0x38c/+0x390), sets +0x398 to 5 and loads
 * sound 0x177.
 *
 * MATCH NOTE: the pool index read is a `const` global copied into a `volatile` local, which
 * hoists the load above the handler stores and parks the value on the stack across the calls. */

#include "nitro/types.h"

struct Subitem {
    char pad000[0x5c];
    unsigned int flags5c;
};

struct Box {
    int xmin, ymin, zmin;
    int xmax, ymax, zmax;
};

struct Ov298Actor {
    char pad000[0x64];
    int camera[4];
    char pad074[0x144 - 0x74];
    char pool144[0x390 - 0x144];
    int poolValue390;
};

extern void Ov298_ReleaseSubObjectsThenNotify(void);
extern void Ov298_PropagateBlockChain(void);
extern void Ov298_HandleMessage(void);
extern void Ov298_CreateNodeRegistryEntry(void);
extern void Ov298_Slot38_StoreValue(void);
extern void func_ov298_020d3ab4(void);
extern void func_ov298_020d3ac0(void);
extern void Ov298_OnHit(void);
extern void Ov298_SwitchAnimation(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Ov107_EnqueueValue(int self, int item);
extern int *List_InsertSorted(void *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern void Res_RequestIdPair(int id);
extern const int data_ov298_020d54e8;

void Ov298_Construct(char *self)
{
    struct Box box;
    int *p;
    int item;
    volatile int variant;
    struct Ov298Actor *actor = (struct Ov298Actor *)self;
    int pose;

    variant = data_ov298_020d54e8;
    box.xmin = -0xeea;
    box.ymin = 0x17;
    box.zmin = -0x858;
    box.xmax = box.xmin + 0x1dd3;
    box.ymax = box.ymin + 0x1c27;
    box.zmax = box.zmin + 0xd64;
    *(void **)(self + 0x8) = Ov298_ReleaseSubObjectsThenNotify;
    *(void **)(self + 0xc) = Ov298_PropagateBlockChain;
    *(void **)(self + 0x1c) = Ov298_HandleMessage;
    *(void **)(self + 0x30) = Ov298_CreateNodeRegistryEntry;
    *(void **)(self + 0x38) = Ov298_Slot38_StoreValue;
    *(void **)(self + 0x28) = func_ov298_020d3ab4;
    *(void **)(self + 0x2c) = func_ov298_020d3ac0;
    *(void **)(self + 0x1d0) = Ov298_OnHit;
    *(void **)(self + 0x1dc) = Ov298_SwitchAnimation;
    *(unsigned char *)(self + 0x1c9) = 2;
    *(u16 *)(self + 0x100 + 0xae) |= 0x200;
    *(int *)(self + 0x70) = 0x1000;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x1000;
    *(int *)(self + 0x6c) = 0;
    *(struct Box *)(self + 0x1fc) = box;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, 1));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x388));
    *(int *)(self + 0x39c) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, variant));
    Ov107_EnqueueValue((int)self, *(int *)(self + 0x39c));
    *(int *)(*(int *)(self + 0x39c) + 0x5c) |= 2;
    *(int **)(self + 0x38c) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x38c) = Ov107_CloneResourceTransform((char *)actor->camera);
    p = List_InsertSorted(actor->pool144, 4, 0x64);
    pose = Ov107_CloneResourceTransform((char *)actor->camera);
    *p = pose;
    actor->poolValue390 = pose;
    *(int *)(self + 0x398) = 5;
    Res_RequestIdPair(0x177);
}
