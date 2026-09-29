/* Constructor of the ov114 enemy: installs the handlers (+8 tick, +0xc draw, +0x1c/+0x20
 * message pair, +0x30 hit callback, +0x1d0 on-hit, +0x1e0 release, +0x1dc finish, +0x34 tick),
 * seeds the +0x64 pose (scale 0x800, y 0x800) and bit 4 of +0x1ae, builds the primary item from
 * pool entry 0 (subscribed, its +4 placement lifted by 0x100), the two sub-items of the
 * overlay's kind pair in a fresh 16-byte slot table (+0x394, attached, bit 1 on their +0x5c),
 * configures action 2 (mode 2, rate 0x1000) and creates two placements from the actor's +0x64
 * pose: +0x388 on the +0x22c list and +0x38c on the +0x144 list; sound 0x112 is loaded. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct Ov114Kinds {
    int a;
    int b;
};

struct Ov114SubitemSlot {
    void *subitem;
    int pad;
};

extern struct Ov114Kinds data_ov277_020d3734;
extern void Ov277_Destroy_3(void);
extern void Ov277_TickAndSyncTwoModelXforms(void);
extern void Ov277_HandleMessage_2(void);
extern void Ov277_SendMessage28(void);
extern void Ov277_CreateRegistryEntryAndLink_3(void);
extern void Ov277_OnHit(void);
extern void Ov277_UpdateNodeReservationState2(void);
extern void Ov277_Model_SetTrack0(void);
extern void Ov277_MaybeForceSubState5ThenReleaseSubObject(void);
extern void *CreateSubitemInstance0xB4();
extern void Srt_SetTranslationXYZ();
extern void RegisterSubscriberSlot();
extern void *CallocInstance();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern int Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov277_Construct_2(int param)
{
    struct Ov114Kinds kinds;
    int i;

    kinds = data_ov277_020d3734;
    *(void **)(param + 0x08) = Ov277_Destroy_3;
    *(void **)(param + 0x0c) = Ov277_TickAndSyncTwoModelXforms;
    *(void **)(param + 0x1c) = Ov277_HandleMessage_2;
    *(void **)(param + 0x20) = Ov277_SendMessage28;
    *(void **)(param + 0x30) = Ov277_CreateRegistryEntryAndLink_3;
    *(void **)(param + 0x1d0) = Ov277_OnHit;
    *(void **)(param + 0x1e0) = Ov277_UpdateNodeReservationState2;
    *(void **)(param + 0x1dc) = Ov277_Model_SetTrack0;
    *(void **)(param + 0x34) = Ov277_MaybeForceSubState5ThenReleaseSubObject;
    *(int *)(param + 0x70) = 0x800;
    *(int *)(param + 0x64) = 0;
    *(int *)(param + 0x68) = 0x800;
    *(int *)(param + 0x6c) = 0;
    *(u16 *)(param + 0x100 + 0xae) |= 0x10;
    {
        int *self = (int *)param;
        ((void **)self)[0xe1] = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 0));
        RegisterSubscriberSlot(self[0x27], ((void **)self)[0xe1]);
        Srt_SetTranslationXYZ((char *)((void **)self)[0xe1] + 4, 0, 0x100, 0);
        ((void **)self)[0xe5] = CallocInstance(0x10);
        for (i = 0; i < 2; i++) {
            ((struct Ov114SubitemSlot *)((void **)self)[0xe5])[i].subitem =
                CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, ((int *)&kinds)[i]));
            Ov107_EnqueueValue(self,
                ((struct Ov114SubitemSlot *)((void **)self)[0xe5])[i].subitem);
            *(int *)((char *)((struct Ov114SubitemSlot *)
                ((void **)self)[0xe5])[i].subitem + 0x5c) |= 2;
        }
        Ov107_Actor_SetAttachSlot(self, 2, 2, 0, 0x1000);
        ((void **)self)[0xe2] = List_InsertSorted(self + 0x8b, 0x10, 100);
        *((int **)self)[0xe2] = Ov107_CloneResourceTransform(self + 0x19);
        {
            int *p = List_InsertSorted(self + 0x51, 4, 100);
            self[0xe3] = *p = Ov107_CloneResourceTransform(self + 0x19);
        }
        Res_RequestIdPair(0x112);
    }
}
