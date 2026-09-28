/* Constructor of the ov297 enemy: installs the handlers (+8 tick, +0xc draw, +0x1c message,
 * +0x30 callback, +0x28/+0x2c veneers, +0x1d0 hit, +0x1dc animation switch), sets +0x1c9 to 2,
 * bit 9 of +0x1ae, the +0x64 pose (scale 0x1000, y 0x1000) and the +0x1fc bounding box; builds
 * the pool entry 0/1 items (+0x384/+0x388, subscribed), the two sub-items of the pool entries
 * listed by the overlay's +0x5690 pair (+0x398/+0x3a0, attached, bit 1), two placements on the
 * +0x22c/+0x144 lists (+0x38c/+0x390) and loads sound 0x176.
 *
 * MATCH NOTE: the pool index pair is a `const` global copied into a local array, which hoists
 * the pair load above the handler stores and parks the values on the stack for the loop. */
#include "nitro/types.h"

struct Subitem {
    char pad000[0x5c];
    unsigned int flags5c;
};

struct Box {
    int xmin, ymin, zmin;
    int xmax, ymax, zmax;
};

struct SubSlot {
    int item;
    int pad4;
};

struct Ov297Actor {
    char pad000[0x64];
    int camera[4];
    char pad074[0x144 - 0x74];
    char pool144[0x390 - 0x144];
    int poolValue390;
    char pad394[4];
    struct SubSlot subs[2];
};

extern void Ov297_ReleaseSubObjectsAndSlotArrayThenNotify(void);
extern void Ov297_PropagateBlockChain(void);
extern void Ov297_HandleMessage(void);
extern void Ov297_CreateNodeRegistryEntry(void);
extern void func_ov297_020d3adc(void);
extern void func_ov297_020d3ae8(void);
extern void Ov297_OnHit(void);
extern void Ov297_SwitchAnimation(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void Ov107_EnqueueValue(int self, int item);
extern int *List_InsertSorted(void *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern void Res_RequestIdPair(int id);
extern const int data_ov297_020d5690[2];

void Ov297_Construct(char *self)
{
    struct Box box;
    int *p;
    int pools[2];
    int i;
    struct Ov297Actor *actor = (struct Ov297Actor *)self;
    int pose;

    pools[0] = data_ov297_020d5690[0];
    pools[1] = data_ov297_020d5690[1];
    box.xmin = -0xeea;
    box.ymin = 0x17;
    box.zmin = -0x858;
    box.xmax = box.xmin + 0x1dd3;
    box.ymax = box.ymin + 0x1c27;
    box.zmax = box.zmin + 0xd64;
    *(void **)(self + 0x8) = Ov297_ReleaseSubObjectsAndSlotArrayThenNotify;
    *(void **)(self + 0xc) = Ov297_PropagateBlockChain;
    *(void **)(self + 0x1c) = Ov297_HandleMessage;
    *(void **)(self + 0x30) = Ov297_CreateNodeRegistryEntry;
    *(void **)(self + 0x28) = func_ov297_020d3adc;
    *(void **)(self + 0x2c) = func_ov297_020d3ae8;
    *(void **)(self + 0x1d0) = Ov297_OnHit;
    *(void **)(self + 0x1dc) = Ov297_SwitchAnimation;
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
    for (i = 0; i < 2; i++) {
        actor->subs[i].item = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, pools[i]));
        Ov107_EnqueueValue((int)self, actor->subs[i].item);
        *(int *)(actor->subs[i].item + 0x5c) |= 2;
    }
    *(int **)(self + 0x38c) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x38c) = Ov107_CloneResourceTransform((char *)actor->camera);
    p = List_InsertSorted(actor->pool144, 4, 0x64);
    pose = (*p = Ov107_CloneResourceTransform((char *)actor->camera));
    actor->poolValue390 = pose;
    Res_RequestIdPair(0x176);
}
