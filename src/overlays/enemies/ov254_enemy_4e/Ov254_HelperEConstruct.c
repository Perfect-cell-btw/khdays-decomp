/* Constructor of an ov254 helper: installs its handlers (+8, +0xc, +0x30 update, +0x1d0 hit
 * filter, +0x1dc), sets bits 2-3 and 9 of +0x1ae and bit 15 of the +0 flags, scale 1.0, +0x54 =
 * 3.0, clears +0x58 and the +0x64 pose, builds the +0x384 item (pose 0x44 of the +0x394 pool,
 * subscribed and re-initialised) and places the +0x64 pose on the +0x22c (+0x388) and +0x144
 * (+0x38c) pools. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef void (*Callback)(void);

extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void RefreshObjectCallbacks(int item, int a);
extern int *List_InsertSorted(void *pool, int elementSize, int capacity);
extern int Ov107_CloneResourceTransform(void *placement);
extern void Ov254_OnDespawn_2(void);
extern void Ov254_PropagateBlockToLinkedNodes(void);
extern void Ov254_CreateRegistryEntryAndLink(void);
extern void Ov254_HelperEHitFilter(void);
extern void Ov254_HelperE_ApplyAnims(void);

void Ov254_HelperEConstruct(char *self)
{
    int pool = *(int *)(self + 0x394);
    int *slot;

    *(Callback *)(self + 0x8) = Ov254_OnDespawn_2;
    *(Callback *)(self + 0xc) = Ov254_PropagateBlockToLinkedNodes;
    *(Callback *)(self + 0x30) = Ov254_CreateRegistryEntryAndLink;
    *(Callback *)(self + 0x1d0) = Ov254_HelperEHitFilter;
    *(Callback *)(self + 0x1dc) = Ov254_HelperE_ApplyAnims;
    *(u16 *)(self + 0x100 + 0xae) |= 0x20c;
    *(u16 *)self |= 0x8000;
    *(int *)(self + 0x70) = 0x1000;
    *(int *)(self + 0x54) = 0x3000;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x64) = 0;
    *(int *)(self + 0x68) = 0;
    *(int *)(self + 0x6c) = 0;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)pool, 0x44));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int *)(self + 0x388) = (int)List_InsertSorted(self + 0x22c, 0x10, 100);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    slot = List_InsertSorted(self + 0x144, 4, 100);
    *(int *)(self + 0x38c) = *slot = Ov107_CloneResourceTransform(self + 0x64);
}
