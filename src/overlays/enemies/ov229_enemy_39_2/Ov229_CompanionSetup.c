/* Setup of the ov229 enemy's companion: installs the +8 tick, +0xc, +0x1c message, +0x30 and +0x1dc
 * handlers, sets bits 1-3 of the +0x60 high byte and bits 2 and 4 of +0x1ae, the +0x64 pose (scale
 * 0.875) and flag 2 of the +0x9c body; the main model (+0x384, item 0x24 of the +0x38c pool) is
 * subscribed with its animation stopped, the +0x390 slot model (kind from data_ov229_020d6918)
 * attached and hidden, and the +0x388 contact built from the pose. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);
typedef struct { int w[1]; } KindTable;
struct bf { unsigned b : 8; };

extern void Ov229_Destroy_2(void);
extern void Ov229_TickAndSyncModelXform(void);
extern void Ov229_EventArmEmitterForward(void);
extern void Ov229_CreateRegistryEntryAndLink(void);
extern void Ov229_Model_ReapplyTracks(void);
extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const KindTable data_ov229_020d6918;

void Ov229_CompanionSetup(char *self)
{
    int pool = *(int *)(self + 0x38c);
    KindTable kinds;
    u16 hw;

    kinds = data_ov229_020d6918;
    *(Callback *)(self + 0x8) = Ov229_Destroy_2;
    *(Callback *)(self + 0xc) = Ov229_TickAndSyncModelXform;
    *(Callback *)(self + 0x1c) = Ov229_EventArmEmitterForward;
    *(Callback *)(self + 0x30) = Ov229_CreateRegistryEntryAndLink;
    *(Callback *)(self + 0x1dc) = Ov229_Model_ReapplyTracks;
    hw = *(u16 *)(self + 0x60);
    *(u16 *)(self + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0xe) << 0x18) >> 0x10);
    *(u16 *)(self + 0x100 + 0xae) |= 0x14;
    *(int *)(self + 0x70) = 0xe00;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    {
        int scale = *(int *)(self + 0x70);

        *(int *)(self + 0x64) = 0;
        *(int *)(self + 0x68) = scale;
        *(int *)(self + 0x6c) = 0;
    }
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 0x24));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x390) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, kinds.w[0]));
    Ov107_EnqueueValue(self, *(int *)(self + 0x390));
    *(int *)(*(int *)(self + 0x390) + 0x5c) |= 2;
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct bf *)(*(int *)(self + 0x388) + 8))->b |= 2;
}
