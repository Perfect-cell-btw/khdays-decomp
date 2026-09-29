/* Constructor of the ov241 enemy (x3: ov241/242/243): installs the handlers (+8 tick, +0xc
 * draw, +0x30/+0x38 hit callbacks, +0x1dc finish), sets +0x1c9 to 2, seeds the +0x64 pose
 * (scale 0x4cd, y 0x4cd), bit 3 of +0x1ae and bit 5 of the +0x60 high byte; builds the primary
 * item from pool entry 0, resolves the "tag_00/01/02" joints into the +0x3ac id triple, back-links
 * the actor into the render object's +0x4c and arms the joint callback (020cfc04, mode 0/6/3),
 * translates the item's +4 placement by (0, 0x200, 0), keeps the "move" motion handle (+0x39c),
 * creates three kind-2 sub-items (+0x38c.., attached, bits 0/1 of their +0x5c, channels 0 and
 * 2 bound, subscribed), an effect node (+0x3a0, subscribed, bit 0) hosting the kind-3 item
 * (+0x388), a placement on the +0x144 list (+0x398) and loads sound 0x13a. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct Bit0 {
    unsigned bit0 : 1;
};

struct Names {
    const char *a;
    const char *b;
    const char *c;
};

extern void Ov242_DestroyObjectsAndInlineArrayThenNotify(void);
extern void Ov242_SetupAndCopyBlock(void);
extern void Ov242_CreateRegistryEntryForActor(void);
extern void Ov242_AllocCopyEntryTable(void);
extern void Ov242_Model_SetTrack0(void);
extern void Ov242_JointCallback(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern int FindResourceIndexByName(int item, const char *name);
extern void NNS_G3dRenderObjSetCallBack(int renderObj, void *cb, int ptr, int timing, int opt);
extern void Srt_SetTranslationXYZ(void *placement, int x, int y, int z);
extern int Ov107_CreateNamedResourceBinding(void *item, const char *name);
extern void SetSubitemState(int item, int channel, int a, int b);
extern int ModelNode_New(void);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern void Res_RequestIdPair(int id);
extern struct Names data_ov242_020d48c4;
extern const char data_ov242_020d4904[];

void Ov242_Construct(char *self)
{
    struct Names names;
    int i;
    int *p;

    *(void **)(self + 0x8) = Ov242_DestroyObjectsAndInlineArrayThenNotify;
    *(void **)(self + 0xc) = Ov242_SetupAndCopyBlock;
    *(void **)(self + 0x30) = Ov242_CreateRegistryEntryForActor;
    *(void **)(self + 0x38) = Ov242_AllocCopyEntryTable;
    *(void **)(self + 0x1dc) = Ov242_Model_SetTrack0;
    *(unsigned char *)(self + 0x1c9) = 2;
    *(int *)(self + 0x70) = 0x4cd;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0x4cd;
    *(int *)(self + 0x6c) = 0;
    *(u16 *)(self + 0x100 + 0xae) |= 8;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x20) << 0x18) >> 0x10);
    }
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)((int)self), 0));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    names = data_ov242_020d48c4;
    for (i = 0; i < 3; i++) {
        if (((const char **)&names)[i] != 0) {
            ((u16 *)self)[0x1d6 + i] = FindResourceIndexByName(*(int *)(self + 0x384), ((const char **)&names)[i]);
        }
    }
    *(char **)(*(int *)(*(int *)(self + 0x384) + 0x88) + 0x4c) = self;
    NNS_G3dRenderObjSetCallBack(*(int *)(*(int *)(self + 0x384) + 0x88) + 0x20, Ov242_JointCallback, 0, 6, 3);
    Srt_SetTranslationXYZ((void *)(*(int *)(self + 0x384) + 4), 0, 0x200, 0);
    *(int *)(self + 0x39c) = Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle((char *)((int)self), 1), data_ov242_020d4904);
    for (i = 0; i < 3; i++) {
        ((int *)self)[0xe3 + i] = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)((int)self), 2));
        Ov107_EnqueueValue((char *)((int)self), ((int *)self)[0xe3 + i]);
        ((struct Bit0 *)(((int *)self)[0xe3 + i] + 0x5c))->bit0 = 1;
        *(int *)(((int *)self)[0xe3 + i] + 0x5c) |= 2;
        SetSubitemState(((int *)self)[0xe3 + i], 0, 0, 1);
        SetSubitemState(((int *)self)[0xe3 + i], 2, 0, 1);
        RegisterSubscriberSlot(*(int *)(self + 0x9c), ((int *)self)[0xe3 + i]);
    }
    *(int *)(self + 0x3a0) = ModelNode_New();
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x3a0));
    ((struct Bit0 *)(*(int *)(self + 0x3a0) + 0x5c))->bit0 = 1;
    *(int *)(self + 0x388) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)((int)self), 3));
    RegisterSubscriberSlot(*(int *)(self + 0x3a0), *(int *)(self + 0x388));
    p = List_InsertSorted(self + 0x144, 4, 0x64);
    *p = Ov107_CloneResourceTransform(self + 0x64);
    *(int *)(self + 0x398) = *p;
    Res_RequestIdPair(0x13a);
}
