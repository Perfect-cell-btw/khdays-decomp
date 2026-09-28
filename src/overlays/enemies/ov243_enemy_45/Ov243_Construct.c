/* Constructor of the ov243 enemy (variant of the ov241/242 constructor): installs the handlers
 * (+8 tick, +0xc draw, +0x30/+0x38 hit callbacks, +0x1dc finish), sets +0x1c9 to 2, seeds the
 * +0x64 pose (scale 0x800, y 0x800), bit 3 of +0x1ae and bit 5 of the +0x60 high byte; builds
 * the primary item from pool entry 0, resolves the "Bone_head" joint into the +0x3a0 id triple,
 * back-links the actor into the render object's +0x4c and arms the joint callback (020d3844,
 * mode 0/6/3), translates the item's +4 placement by (0, 0x200, 0), keeps the "move" motion
 * handle (+0x390), creates an effect node (+0x394, subscribed, bit 0) hosting the kind-2 item
 * (+0x388), a placement on the +0x144 list (+0x38c) and loads sound 0x13b. */

#include "nitro/types.h"

struct Bit0 {
    unsigned bit0 : 1;
};

struct Names {
    const char *a;
    const char *b;
    const char *c;
};

extern void Ov243_ReleaseSubObjectsGuardedThenNotify(void);
extern void Ov243_SetupAndCopyBlock(void);
extern void Ov243_CreateRegistryEntryAndLink(void);
extern void Ov243_AllocCopyEntryTable(void);
extern void Ov243_Model_SetTrack0(void);
extern void Ov243_JointCallback(void);
extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int FindResourceIndexByName(int item, const char *name);
extern void NNS_G3dRenderObjSetCallBack(int renderObj, void *cb, int ptr, int timing, int opt);
extern void Srt_SetTranslationXYZ(void *placement, int x, int y, int z);
extern int Ov107_CreateNamedResourceBinding(void *item, const char *name);
extern int ModelNode_New(void);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern void Res_RequestIdPair(int id);
extern struct Names data_ov243_020d4748;
extern const char data_ov243_020d4778[];

void Ov243_Construct(char *self)
{
    struct Names names;
    int i;
    int *p;

    *(void **)(self + 0x8) = Ov243_ReleaseSubObjectsGuardedThenNotify;
    *(void **)(self + 0xc) = Ov243_SetupAndCopyBlock;
    *(void **)(self + 0x30) = Ov243_CreateRegistryEntryAndLink;
    *(void **)(self + 0x38) = Ov243_AllocCopyEntryTable;
    *(void **)(self + 0x1dc) = Ov243_Model_SetTrack0;
    *(unsigned char *)(self + 0x1c9) = 2;
    *(int *)(self + 0x70) = 0x800;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x800;
    *(int *)(self + 0x6c) = 0;
    *(u16 *)(self + 0x100 + 0xae) |= 8;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x20) << 0x18) >> 0x10);
    }
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    names = data_ov243_020d4748;
    for (i = 0; i < 3; i++) {
        if (((const char **)&names)[i] != 0) {
            ((u16 *)self)[0x1d0 + i] = FindResourceIndexByName(*(int *)(self + 0x384), ((const char **)&names)[i]);
        }
    }
    *(char **)(*(int *)(*(int *)(self + 0x384) + 0x88) + 0x4c) = self;
    NNS_G3dRenderObjSetCallBack(*(int *)(*(int *)(self + 0x384) + 0x88) + 0x20, Ov243_JointCallback, 0, 6, 3);
    Srt_SetTranslationXYZ((void *)(*(int *)(self + 0x384) + 4), 0, 0x200, 0);
    *(int *)(self + 0x390) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle((int)self, 1), data_ov243_020d4778);
    *(int *)(self + 0x394) = ModelNode_New();
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x394));
    ((struct Bit0 *)(*(int *)(self + 0x394) + 0x5c))->bit0 = 1;
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((int)self, 2));
    RegisterSubscriberSlot(*(int *)(self + 0x394), *(int *)(self + 0x388));
    p = List_InsertSorted(self + 0x144, 4, 0x64);
    *p = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x38c) = *p;
    Res_RequestIdPair(0x13b);
}
