/* Constructor of an ov254 helper: installs its handlers (+8, +0x1c message, +0x30 update, +0x1dc),
 * sets bits 1-3, 5 and 6 of the +0x60 high byte and bit 2 of +0x1ae, a tiny scale, clears +0x54 /
 * +0x58, marks the +0x9c parent, builds the +0x384 item (pose 0x4a of the +0x38c pool, subscribed
 * and re-initialised) and the hidden +0x390 item (pose 0x4b, registered). */
#include "nitro/types.h"
typedef void (*Callback)(void);

extern void *Ov107_PackTextureHandle(int pool, int index);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int item, int a);
extern void Ov107_EnqueueValue(char *self, int item);
extern void Ov254_Destroy_2(void);
extern void Ov254_HelperAHandleMessage(void);
extern void Ov254_HelperD_CreateAiTask(void);
extern void Ov254_HelperD_ApplyAnims(void);

void Ov254_HelperDConstruct(char *self)
{
    int pool = *(int *)(self + 0x38c);

    *(Callback *)(self + 0x8) = Ov254_Destroy_2;
    *(Callback *)(self + 0x1c) = Ov254_HelperAHandleMessage;
    *(Callback *)(self + 0x30) = Ov254_HelperD_CreateAiTask;
    *(Callback *)(self + 0x1dc) = Ov254_HelperD_ApplyAnims;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x6e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 1;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x4a));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(pool, 0x4b));
    Ov107_EnqueueValue(self, *(int *)(self + 0x390));
    *(int *)(*(int *)(self + 0x390) + 0x5c) |= 2;
}
