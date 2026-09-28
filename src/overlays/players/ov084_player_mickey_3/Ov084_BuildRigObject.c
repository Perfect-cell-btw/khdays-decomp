/* Constructor for the ov047 panel object: takes the root heap block as the object,
 * publishes it in the overlay's global slot, stamps the identity fields from the
 * caller's config, opens the object with its display parameters under a fixed name,
 * installs the handler table at +0x664, binds the rig, invalidates the five cached
 * slots at +0x514, resolves four bone indices off the rig, and finally raises the
 * three optional feature flags the config asked for. */
#include "nitro/types.h"

struct PanelInitConfig {
    int objectType;
    int slotId;
    u8 bitIndex;
    u8 pad09[3];
    int enableLowFlag;
    int enableMidFlag;
    int enableHighFlag;
};

struct Ov044OpenParams {
    int enabled;
    int limit;
    int scale;
    int unused0c;
    int unused10;
};

struct Ov044RigHeader {
    int pad0;
    int rig;
};

static inline int Ov044_GetBoneBase(char *object)
{
    int rig = ((struct Ov044RigHeader *)(
        *(int *)(object + 0x20) + 0x24))->rig;
    return rig != 0 ? rig + 0x40 : 0;
}

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Entity_ForwardToSlot(int, u16, int, void *, int);
extern void TailForwardTrackEntry(int, void *, int, int);
extern int ArrayEntryPtrD0(int);
extern void Actor_InitEntityLink(void *, int);
extern int NNS_G3dGetResDictIdxByName(void *, void *);
extern void Ov022_InitActor(void *);

extern void Ov084_ApplyModeChange(void);
extern void Ov084_TickPairedState(void);
extern void Ov084_InvokeSubHandlerPairWithGlobalBuffer(void);
extern void Ov084_initFlagStateRegionMarshal(void);
extern void Ov084_MapSlotKindToAnim(void);
extern void Ov084_HandleMsgAndFacePartner(void);
extern void Ov084_AcquireGridSlots(void);
extern void Ov084_FlagLocalAndEnterState21(void);

extern void *data_ov084_020b9a20;
extern const char data_ov084_020b99a8[];
extern int data_ov084_020b9948;
extern int data_ov084_020b9938;
extern int data_ov084_020b9958;
extern int data_ov084_020b9968;

void Ov084_BuildRigObject(struct PanelInitConfig *config)
{
    struct Ov044OpenParams params;
    char *object = (char *)NNSi_FndGetCurrentRootHeap();
    int i;
    int bone;

    data_ov084_020b9a20 = object;
    object[9] = (char)config->objectType;
    object[0x4bc] = (char)config->slotId;
    object[8] = config->bitIndex;
    *(int *)(object + 0xc) = 0x10;
    *(long long *)object = 0;

    params.enabled = 1;
    params.scale = 9 << 8;
    params.limit = 7 << 8;
    Entity_ForwardToSlot(*(signed char *)(object + 0x4bc),
                  (u16)(1 << *(u8 *)(object + 8)), 0, &params, 0);

    TailForwardTrackEntry(*(signed char *)(object + 0x4bc), (void *)data_ov084_020b99a8, 1,
                  config->objectType + 7);

    *(void **)(object + 0x664 + 0x00) = (void *)&Ov084_ApplyModeChange;
    *(void **)(object + 0x664 + 0x04) = (void *)&Ov084_TickPairedState;
    *(void **)(object + 0x664 + 0x08) = (void *)&Ov084_InvokeSubHandlerPairWithGlobalBuffer;
    *(void **)(object + 0x664 + 0x0c) = 0;
    *(void **)(object + 0x664 + 0x10) = 0;
    *(void **)(object + 0x664 + 0x14) = (void *)&Ov084_initFlagStateRegionMarshal;
    *(void **)(object + 0x664 + 0x18) = (void *)&Ov084_MapSlotKindToAnim;
    *(void **)(object + 0x664 + 0x20) = (void *)&Ov084_HandleMsgAndFacePartner;
    *(void **)(object + 0x664 + 0x28) = (void *)&Ov084_AcquireGridSlots;
    *(void **)(object + 0x664 + 0x24) = (void *)&Ov084_FlagLocalAndEnterState21;

    Actor_InitEntityLink(object + 0x20,
                  ArrayEntryPtrD0(*(signed char *)(object + 0x4bc)));

    i = 0;
    goto test;
body:
    *(int *)(object + i * sizeof(int) + 0x514) = -1;
    i++;
test:
    if (i < 5) {
        goto body;
    }

    bone = Ov044_GetBoneBase(object);
    *(int *)(object + 0x520) = bone != 0
        ? NNS_G3dGetResDictIdxByName((void *)bone, &data_ov084_020b9948) : -1;
    bone = Ov044_GetBoneBase(object);
    *(int *)(object + 0x518) = bone != 0
        ? NNS_G3dGetResDictIdxByName((void *)bone, &data_ov084_020b9938) : -1;
    bone = Ov044_GetBoneBase(object);
    *(int *)(object + 0x51c) = bone != 0
        ? NNS_G3dGetResDictIdxByName((void *)bone, &data_ov084_020b9958) : -1;
    bone = Ov044_GetBoneBase(object);
    *(int *)(object + 0x524) = bone != 0
        ? NNS_G3dGetResDictIdxByName((void *)bone, &data_ov084_020b9968) : -1;

    if (config->enableLowFlag != 0) {
        *(long long *)object |= 0x20;
    }
    if (config->enableMidFlag != 0) {
        *(long long *)object |= 0x10000;
    }
    if (config->enableHighFlag != 0) {
        *(long long *)object |= 0x1000000000LL;
    }
    Ov022_InitActor(object);
}
