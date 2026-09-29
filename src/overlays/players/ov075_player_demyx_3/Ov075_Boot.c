/* Ov075_Boot -- overlay boot of the ov036 enemy (x4: ov036/054/074/091): the ov042 shape (see
 * Ov042_BuildRigObject for the load-bearing forms): grabs the root heap block as the object, latches
 * it in the overlay global, copies the identity fields from the caller's config, opens the slot
 * with the {1, 0x1700, 0x900} parameter block, binds the animation table -- the alternate one when the config's flag at +0x18 is set, fills the handler vtable
 * at +0x664, attaches the scene node, invalidates the five bone handles and resolves 3 of them by
 * name, folds the three optional capability bits into the 64-bit flag word and hands the object
 * over. */

#include "game/engine.h"

extern void *NNSi_FndGetCurrentRootHeap(void);
extern int  NNS_G3dGetResDictIdxByName(void *node, void *desc);
extern void Ov022_InitActor(void *obj);

extern void Ov075_ApplyModeChange(void);
extern void Ov075_UpdateAnchor(void);
extern void Ov075_UpdateAimAndFlagLocal(void);
extern void Ov075_initFlagStateRegionMarshal(void);
extern void Ov075_MapSlotKindToAnim(void);
extern void Ov075_SelectRequestHandler3(void);
extern void Ov075_FirePartShot(void);
extern void Ov075_BuildRenderHandles(void);
extern void Ov075_InitStateFieldFromQuery(void);
extern void *data_ov075_020b9e20;
extern int data_ov075_020b9d48;
extern int data_ov075_020b9d5c;
extern int data_ov075_020b9ce8;
extern int data_ov075_020b9cf8;
extern int data_ov075_020b9d08;

/* The rig hangs off the scene node at +0x28; each bone block starts 0x40 further in. */
typedef struct { int pad[1]; int f4; } RigHdr;

static inline int bone(char *obj) {
    int p = ((RigHdr *)(*(int *)(obj + 0x20) + 0x24))->f4;
    return p != 0 ? p + 0x40 : 0;
}

void Ov075_Boot(int *cfg) {
    struct { int a, b, c, d, e; } params;
    char *obj = (char *)NNSi_FndGetCurrentRootHeap();
    int i;
    int b;

    data_ov075_020b9e20 = obj;
    obj[9] = (char)cfg[0];
    obj[0x4bc] = (char)cfg[1];
    obj[8] = *(unsigned char *)((char *)cfg + 8);
    *(int *)(obj + 0xc) = 6;
    *(long long *)obj = 0;

    params.a = 1;
    params.c = 9 << 8;
    params.b = 0x1700;
    Entity_ForwardToSlot(*(signed char *)(obj + 0x4bc),
                         (unsigned short)(1 << *(unsigned char *)(obj + 8)), 0, &params, 0);

    if (cfg[6] == 0) {
        TailForwardTrackEntry(*(signed char *)(obj + 0x4bc), &data_ov075_020b9d48, 1, cfg[0] + 7);
    } else {
        TailForwardTrackEntry(*(signed char *)(obj + 0x4bc), &data_ov075_020b9d5c, 1, cfg[0] + 7);
    }
    *(void **)(obj + 0x664 + 0x00) = (void *)&Ov075_ApplyModeChange;
    *(void **)(obj + 0x664 + 0x04) = (void *)&Ov075_UpdateAnchor;
    *(void **)(obj + 0x664 + 0x08) = (void *)&Ov075_UpdateAimAndFlagLocal;
    *(void **)(obj + 0x664 + 0x0c) = 0;
    *(void **)(obj + 0x664 + 0x10) = 0;
    *(void **)(obj + 0x664 + 0x14) = (void *)&Ov075_initFlagStateRegionMarshal;
    *(void **)(obj + 0x664 + 0x18) = (void *)&Ov075_MapSlotKindToAnim;
    *(void **)(obj + 0x664 + 0x20) = (void *)&Ov075_SelectRequestHandler3;
    *(void **)(obj + 0x664 + 0x1c) = (void *)&Ov075_FirePartShot;
    *(void **)(obj + 0x664 + 0x28) = (void *)&Ov075_BuildRenderHandles;
    *(void **)(obj + 0x664 + 0x24) = (void *)&Ov075_InitStateFieldFromQuery;

    Actor_InitEntityLink(obj + 0x20, ArrayEntryPtrD0(*(signed char *)(obj + 0x4bc)));

    i = 0;
    goto test;
body:
    *(int *)(obj + i * sizeof(int) + 0x514) = -1;
    i++;
test:
    if (i < 5) {
        goto body;
    }

    b = bone(obj);
    *(int *)(obj + 0x520) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov075_020b9ce8) : -1;
    b = bone(obj);
    *(int *)(obj + 0x51c) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov075_020b9cf8) : -1;
    b = bone(obj);
    *(int *)(obj + 0x524) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov075_020b9d08) : -1;
    if (cfg[3] != 0) {
        *(long long *)obj |= 0x20;
    }
    if (cfg[4] != 0) {
        *(long long *)obj |= 0x10000;
    }
    if (cfg[5] != 0) {
        *(long long *)obj |= 0x1000000000LL;
    }
    Ov022_InitActor(obj);
}
