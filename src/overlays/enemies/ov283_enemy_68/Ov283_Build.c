/* Build the ov283 actor: its brain (020cf328), message (020cf34c) and spawn (020cf488) callbacks are
 * installed, bits 1-3 and 6 of the +0x60 high byte and bits 2/4 of +0x1ae are set, the body radius is
 * 0.25; model 2 of the +0x38c set becomes the +0x384 rig (subscribed to the scene, pose reset) and the
 * data_ov283_020cfbc8 model becomes the attached, hidden +0x390 model. */
#include "nitro/types.h"
typedef struct { int id; } Ids;

extern const Ids data_ov283_020cfbc8;
extern void Ov283_Destroy(void);
extern void Ov283_OnMessage(void);
extern void Ov283_CreateRegistryEntryAndLink(void);
extern void *Ov107_PackTextureHandle(int set, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int rig, int a);
extern void Ov107_EnqueueValue(char *self, int model);

void Ov283_Build(char *self)
{
    int set = *(int *)(self + 0x38c);
    Ids ids;

    ids = data_ov283_020cfbc8;
    *(void **)(self + 8) = Ov283_Destroy;
    *(void **)(self + 0x1c) = Ov283_OnMessage;
    *(void **)(self + 0x30) = Ov283_CreateRegistryEntryAndLink;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x1ae) |= 0x14;
    *(int *)(self + 0x70) = 0x400;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(set, 2));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    Ov107_EnqueueValue(self, *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(set, ids.id)));
    *(int *)(*(int *)(self + 0x390) + 0x5c) |= 2;
}
