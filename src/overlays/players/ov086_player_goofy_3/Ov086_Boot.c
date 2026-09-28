/* Ov086_Boot -- overlay boot of the ov048 enemy (x4: ov048/067/086/103): the ov042 shape (see
 * Ov042_BuildRigObject for the load-bearing forms): grabs the root heap block as the object, latches
 * it in the overlay global, copies the identity fields from the caller's config, opens the slot
 * with the {1, 0x1700, 0x900} parameter block, binds the animation table, fills the handler vtable
 * at +0x664, attaches the scene node, invalidates the five bone handles and resolves 4 of them by
 * name, folds the three optional capability bits into the 64-bit flag word and hands the object
 * over. */
extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Entity_ForwardToSlot(int id, unsigned short mask, int a, void *params, int b);
extern void TailForwardTrackEntry(int id, void *tbl, int n, int p);
extern int  ArrayEntryPtrD0(int id);
extern void Actor_InitEntityLink(void *dst, int src);
extern int  NNS_G3dGetResDictIdxByName(void *node, void *desc);
extern void Ov022_InitActor(void *obj);

extern void Ov086_ApplyMode(void);
extern void Ov086_SyncLocalPlayerHandle(void);
extern void Ov086_StepAttackSlotAndForward(void);
extern void Ov086_initSharedObjSetReadyFlag(void);
extern void Ov086_MapSlotKindToAnim(void);
extern void Ov086_HandleMessage(void);
extern void Ov086_BuildRenderHandles(void);
extern void Ov086_FlagLocalAndEnterState21(void);
extern void *data_ov086_020b9a60;
extern int data_ov086_020b99c8;
extern int data_ov086_020b995c;
extern int data_ov086_020b994c;
extern int data_ov086_020b993c;
extern int data_ov086_020b992c;

/* The rig hangs off the scene node at +0x28; each bone block starts 0x40 further in. */
typedef struct { int pad[1]; int f4; } RigHdr;

static inline int bone(char *obj) {
    int p = ((RigHdr *)(*(int *)(obj + 0x20) + 0x24))->f4;
    return p != 0 ? p + 0x40 : 0;
}

void Ov086_Boot(int *cfg) {
    struct { int a, b, c, d, e; } params;
    char *obj = (char *)NNSi_FndGetCurrentRootHeap();
    int i;
    int b;

    data_ov086_020b9a60 = obj;
    obj[9] = (char)cfg[0];
    obj[0x4bc] = (char)cfg[1];
    obj[8] = *(unsigned char *)((char *)cfg + 8);
    *(int *)(obj + 0xc) = 18;
    *(long long *)obj = 0;

    params.a = 1;
    params.c = 9 << 8;
    params.b = 0x1700;
    Entity_ForwardToSlot(*(signed char *)(obj + 0x4bc),
                  (unsigned short)(1 << *(unsigned char *)(obj + 8)), 0, &params, 0);

    TailForwardTrackEntry(*(signed char *)(obj + 0x4bc), &data_ov086_020b99c8, 1, cfg[0] + 7);
    *(void **)(obj + 0x664 + 0x00) = (void *)&Ov086_ApplyMode;
    *(void **)(obj + 0x664 + 0x04) = (void *)&Ov086_SyncLocalPlayerHandle;
    *(void **)(obj + 0x664 + 0x08) = (void *)&Ov086_StepAttackSlotAndForward;
    *(void **)(obj + 0x664 + 0x0c) = 0;
    *(void **)(obj + 0x664 + 0x10) = 0;
    *(void **)(obj + 0x664 + 0x14) = (void *)&Ov086_initSharedObjSetReadyFlag;
    *(void **)(obj + 0x664 + 0x18) = (void *)&Ov086_MapSlotKindToAnim;
    *(void **)(obj + 0x664 + 0x20) = (void *)&Ov086_HandleMessage;
    *(void **)(obj + 0x664 + 0x28) = (void *)&Ov086_BuildRenderHandles;
    *(void **)(obj + 0x664 + 0x24) = (void *)&Ov086_FlagLocalAndEnterState21;

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
    *(int *)(obj + 0x520) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov086_020b995c) : -1;
    b = bone(obj);
    *(int *)(obj + 0x518) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov086_020b994c) : -1;
    b = bone(obj);
    *(int *)(obj + 0x51c) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov086_020b993c) : -1;
    b = bone(obj);
    *(int *)(obj + 0x524) = b != 0 ? NNS_G3dGetResDictIdxByName((void *)b, &data_ov086_020b992c) : -1;
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
