/* Construction of the ov137 actor: installs its five handlers, configures the
 * actor and parent flags, creates and registers the primary and secondary
 * subitems, and links the actor's pose into its sorted registry. */

#include "nitro/types.h"
#include "game/enemy_common.h"

struct Ov137Pose {
    int w;
};

struct Ov137Byte8 {
    u32 lo : 8;
    u32 rest : 24;
};

struct Ov137ChildSlot {
    int pChild;
};

struct Ov137Actor {
    char pad_000[0x390];
    struct Ov137ChildSlot *pSecondarySlot;
};

extern int CreateSubitemInstance0xB4(void *item);
extern int RegisterSubscriberSlot(int subscriber, int item);
extern void SetSubitemState(int item, int channel, int a, int b);
extern void RefreshObjectCallbacks(int item, int a);
extern void *CallocInstance(int size);
extern int *List_InsertSorted(char *list, int stride, int max);
extern int Ov107_CloneResourceTransform(char *pose);
extern const struct Ov137Pose data_ov137_020cf39c;
extern void Ov137_SubObject_Destroy(void);
extern void Ov137_TickAndSyncModelXform(void);
extern void Ov137_HandleMessage(void);
extern void Ov137_CreateRegistryEntryAndLink(void);
extern void Ov137_HandleBounce(void);

void Ov137_InitializeActor(struct Ov137Actor *actor)
{
    char *self = (char *)actor;
    struct Ov137Pose pose = data_ov137_020cf39c;
    int *secondarySlot;
    int secondaryCreated;

    *(void **)(self + 0x8) = Ov137_SubObject_Destroy;
    *(void **)(self + 0xc) = Ov137_TickAndSyncModelXform;
    *(void **)(self + 0x1c) = Ov137_HandleMessage;
    *(void **)(self + 0x30) = Ov137_CreateRegistryEntryAndLink;
    *(void **)(self + 0x1d0) = Ov137_HandleBounce;
    {
        u16 hw = *(u16 *)(self + 0x60);
        *(u16 *)(self + 0x60) = (hw & ~0xff00) |
            ((((((unsigned int)hw << 0x10) >> 0x18) | 0x4e) << 0x18) >> 0x10);
    }
    *(u16 *)(self + 0x100 + 0xae) |= 4;
    *(int *)(self + 0x70) = 0x800;
    *(int *)(*(int *)(self + 0x9c) + 0x5c) |= 4;
    *(int *)(self + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)(*(int *)(self + 0x38c)), 6));
    RegisterSubscriberSlot(*(int *)(self + 0x9c), *(int *)(self + 0x384));
    SetSubitemState(*(int *)(self + 0x384), 0, 0, 1);
    SetSubitemState(*(int *)(self + 0x384), 2, 0, 1);
    RefreshObjectCallbacks(*(int *)(self + 0x384), 0);
    *(int **)(self + 0x390) = CallocInstance(8);
    secondaryCreated = CreateSubitemInstance0xB4(Ov107_PackTextureHandle((char *)(*(int *)(self + 0x38c)), pose.w));
    secondarySlot = *(int **)(self + 0x390);
    *secondarySlot = secondaryCreated;
    secondarySlot = *(int * volatile *)(self + 0x390);
    Ov107_EnqueueValue((char *)actor, *secondarySlot);
    *(int *)(**(int **)(self + 0x390) + 0x5c) |= 2;
    *(int **)(self + 0x388) = List_InsertSorted(self + 0x22c, 0x10, 0x64);
    **(int **)(self + 0x388) = Ov107_CloneResourceTransform(self + 0x64);
    ((struct Ov137Byte8 *)(*(int **)(self + 0x388) + 2))->lo |= 2;
}
