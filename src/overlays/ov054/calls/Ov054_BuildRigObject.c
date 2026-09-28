typedef unsigned char u8;

struct InitConfig {
    int type;
    int slot;
    u8 bit;
    u8 pad[3];
    int low;
    int mid;
    int high;
};

struct OpenParams { int enabled, limit, scale, unused0c, unused10; };
struct RigHeader { int unused, rig; };

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void Entity_ForwardToSlot(int, unsigned short, int, void *, int);
extern void TailForwardTrackEntry(int, void *, int, int);
extern int LoadGlobalU16At0(void);
extern int ArrayEntryPtrD0(int);
extern void Actor_InitEntityLink(void *, int);
extern int NNS_G3dGetResDictIdxByName(void *, void *);
extern void Ov022_InitActor(void *);

extern void Ov054_ApplyModeChange(void);
extern void Ov054_Weapon_TickStreams(void);
extern void Ov054_StepSlotAndForward(void);
extern void Ov054_initFlagStateRegionMarshal(void);
extern void Ov054_MapSlotKindToAnim(void);
extern void Ov054_EnterActorState(void);
struct Runtime;
typedef u8 (*SetupHandler)(struct Runtime *);
typedef int (*StateHandler)(int *);
extern u8 Ov054_RegisterHandlersAndArm(struct Runtime *);
extern int Ov054_FlagLocalAndEnterState21(int *);
extern void *data_ov054_020b74a0;
extern char data_ov054_020b741c[];
extern char data_ov054_020b73bc[];
extern char data_ov054_020b73cc[];
extern char data_ov054_020b73ac[];
extern char data_ov054_020b738c[];
extern char data_ov054_020b739c[];

static inline int bone(char *obj) {
    int rig = ((struct RigHeader *)(*(int *)(obj + 0x20) + 0x24))->rig;
    return rig != 0 ? rig + 0x40 : 0;
}

void Ov054_BuildRigObject(struct InitConfig *cfg) {
    struct OpenParams p;
    char *obj = (char *)NNSi_FndGetCurrentRootHeap();
    int i, b, mode;

    data_ov054_020b74a0 = obj;
    obj[9] = (char)cfg->type;
    obj[0x4bc] = (char)cfg->slot;
    obj[8] = cfg->bit;
    *(int *)(obj + 0xc) = 5;
    *(long long *)obj = 0;

    p.enabled = 1;
    p.scale = 0x900;
    p.limit = 0xf00;
    Entity_ForwardToSlot(*(signed char *)(obj + 0x4bc),
                  (unsigned short)(1 << *(u8 *)(obj + 8)), 0, &p, 0);
    TailForwardTrackEntry(*(signed char *)(obj + 0x4bc), data_ov054_020b741c,
                  1, cfg->type + 7);

    *(void **)(obj + 0x664) = (void *)&Ov054_ApplyModeChange;
    *(void **)(obj + 0x668) = (void *)&Ov054_Weapon_TickStreams;
    *(void **)(obj + 0x66c) = (void *)&Ov054_StepSlotAndForward;
    *(void **)(obj + 0x670) = 0;
    *(void **)(obj + 0x674) = 0;
    *(void **)(obj + 0x678) = (void *)&Ov054_initFlagStateRegionMarshal;
    *(void **)(obj + 0x67c) = (void *)&Ov054_MapSlotKindToAnim;
    *(void **)(obj + 0x684) = (void *)&Ov054_EnterActorState;

    mode = LoadGlobalU16At0();
    if (mode != 0x2a) {
        *(SetupHandler *)(obj + 0x68c) = Ov054_RegisterHandlersAndArm;
    } else {
        *(SetupHandler *)(obj + 0x68c) = 0;
    }
    *(StateHandler *)(obj + 0x688) = Ov054_FlagLocalAndEnterState21;

    Actor_InitEntityLink(obj + 0x20, ArrayEntryPtrD0(*(signed char *)(obj + 0x4bc)));
    i = 0;
    goto test;
body:
    *(int *)(obj + i * sizeof(int) + 0x514) = -1;
    i++;
test:
    if (i < 5) goto body;

    b = bone(obj);
    *(int *)(obj + 0x520) = b ? NNS_G3dGetResDictIdxByName((void *)b, data_ov054_020b73bc) : -1;
    b = bone(obj);
    *(int *)(obj + 0x518) = b ? NNS_G3dGetResDictIdxByName((void *)b, data_ov054_020b73cc) : -1;
    b = bone(obj);
    *(int *)(obj + 0x514) = b ? NNS_G3dGetResDictIdxByName((void *)b, data_ov054_020b73ac) : -1;
    b = bone(obj);
    *(int *)(obj + 0x51c) = b ? NNS_G3dGetResDictIdxByName((void *)b, data_ov054_020b738c) : -1;
    b = bone(obj);
    *(int *)(obj + 0x524) = b ? NNS_G3dGetResDictIdxByName((void *)b, data_ov054_020b739c) : -1;

    if (cfg->low) *(long long *)obj |= 0x20;
    if (cfg->mid) *(long long *)obj |= 0x10000;
    if (cfg->high) *(long long *)obj |= 0x1000000000LL;
    Ov022_InitActor(obj);
}
