/* ov281 actor initializer: install callbacks, build actor bounds, resolve twelve bone
 * handles, configure four actions, create their subitems and seed two pose handles.
 *
 * The per-overlay fixed-point values are load-bearing: 0x14cc for the pose, 0x2998 for
 * action zero and 0x1b4c for the remaining actions.  Unlike the nearby ov188/ov190
 * homologs, these values require literal-pool loads and account for the extra 12 bytes. */
struct v3 { int a, b, c; };
struct Box { struct v3 min, max; };
struct Pose { struct v3 v; int nScale; };

struct Ov281Actor {
    char pad000[0x08];
    void *fn008;
    void *fn00c;
    char pad010[0x0c];
    void *fn01c;
    char pad020[0x08];
    void *fn028;
    void *fn02c;
    void *fn030;
    void *fn034;
    char pad038[0x2c];
    int camera[4];
    char pad074[0x15c];
    void *fn1d0;
    char pad1d4[0x08];
    void *fn1dc;
    void *fn1e0;
    void *fn1e4;
    char pad1e8[0x14];
    struct Box box1fc;
};

extern struct v3 data_02041dc8;

extern unsigned short data_ov281_020ce48c[];
extern unsigned short data_ov281_020ce494[];
extern unsigned short data_ov281_020ce49c[];
extern unsigned short data_ov281_020ce4a8[];
extern unsigned short data_ov281_020ce4b8[];
extern unsigned short data_ov281_020ce4c8[];
extern unsigned short data_ov281_020ce4d4[];
extern unsigned short data_ov281_020ce4e4[];
extern unsigned short data_ov281_020ce4f0[];
extern unsigned short data_ov281_020ce500[];
extern unsigned short data_ov281_020ce510[];
extern unsigned short data_ov281_020ce520[];
extern int data_ov281_020ce530;

extern int Ov281_ReleaseSubObjectsAndSlotArrayThenNotify, Ov281_TickWithChildRefresh, Ov281_HandleActorCommand;
extern int Ov281_SpawnActorRegistryEntry, func_ov281_020cc63c, func_ov281_020cc648;
extern int Ov281_ReleaseByStateAndPublishPose, Ov281_ProcessHitReaction, Ov281_Model_ReapplyTrack0;
extern int Ov281_RequestSubState10IfNotCurrent, Ov281_RequestSubState11IfIdle;

extern void *Ov107_PackTextureHandle();
extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void *InsertSortedEntryWithKey();
extern void *Ov107_CreateNamedResourceBinding();
extern void Ov107_EnqueueValue();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();
extern void Res_RequestIdPair(int nId);

void Ov281_InitializeActor(struct Ov281Actor *actor) {
    int minX;
    int minY;
    int minZ;
    register int cameraScale;
    register int actionScale;
    register void *fn2c;

    struct Box box;
    struct Pose g;
    char *pg;
    void *sub;
    long long r;

    minX = -0xeea;
    minZ = -0x858;
    minY = 0x17;
    cameraScale = 0x14cc;

    actor->fn008 = &Ov281_ReleaseSubObjectsAndSlotArrayThenNotify;
    actor->fn00c = &Ov281_TickWithChildRefresh;
    actor->fn01c = &Ov281_HandleActorCommand;
    actor->fn030 = &Ov281_SpawnActorRegistryEntry;
    actor->fn028 = &func_ov281_020cc63c;

    fn2c = &func_ov281_020cc648;

    box.min.a = minX;
    box.min.b = minY;
    box.min.c = minZ;
    box.max.a = box.min.a + 0x1dd3;
    box.max.b = box.min.b + 0x1c27;
    box.max.c = box.min.c + 0xd64;

    actor->fn02c = fn2c;
    actor->fn034 = &Ov281_ReleaseByStateAndPublishPose;
    actor->fn1d0 = &Ov281_ProcessHitReaction;
    actor->fn1dc = &Ov281_Model_ReapplyTrack0;
    actor->fn1e0 = &Ov281_RequestSubState10IfNotCurrent;
    actor->fn1e4 = &Ov281_RequestSubState11IfIdle;
    actor->camera[3] = cameraScale;
    actor->camera[0] = 0;
    actor->camera[1] = cameraScale;
    actor->camera[2] = 0;

    actor->box1fc = box;

    *(void **)(((unsigned int)actor) + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(((unsigned int)actor), 0));
    {
        int *self = (int *)actor;
        RegisterSubscriberSlot(self[0x27], ((void **)self)[0xe1]);
        ((void **)self)[0xe4] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce48c);
        ((void **)self)[0xe5] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce494);
        ((void **)self)[0xe6] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce49c);
        ((void **)self)[0xe7] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4a8);
        ((void **)self)[0xe8] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4b8);
        ((void **)self)[0xe9] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4c8);
        ((void **)self)[0xea] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4d4);
        ((void **)self)[0xeb] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4e4);
        ((void **)self)[0xec] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce4f0);
        ((void **)self)[0xed] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce500);
        ((void **)self)[0xee] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce510);
        ((void **)self)[0xef] = InsertSortedEntryWithKey(self[0xe1], 1, data_ov281_020ce520);

        ((void **)self)[0xf0] =
            Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(self, 1), &data_ov281_020ce530);

        actionScale = 0x2998;
        Ov107_Actor_SetAttachSlot(self, 0, 1, 0, actionScale);
        actionScale = 0x1b4c;
        Ov107_Actor_SetAttachSlot(self, 2, 1, 0, actionScale);
        Ov107_Actor_SetAttachSlot(self, 1, 1, 0, actionScale);
        Ov107_Actor_SetAttachSlot(self, 4, 1, 0, actionScale);

        ((void **)self)[0xf2] = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 2));
        sub = ((void **)self)[0xf2];
        Ov107_EnqueueValue(self, sub);
        *(int *)((char *)sub + 0x5c) |= 2;

        Ov107_EnqueueValue(self, sub = ((void **)self)[0xf4] =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 3)));
        *(int *)((char *)sub + 0x5c) |= 2;

        Ov107_EnqueueValue(self, sub = ((void **)self)[0xf6] =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 4)));
        *(int *)((char *)sub + 0x5c) |= 2;

        Ov107_EnqueueValue(self, sub = ((void **)self)[0xf8] =
            CreateSubitemInstance0xB4(Ov107_PackTextureHandle(self, 5)));
        *(int *)((char *)sub + 0x5c) |= 2;

        g = *(struct Pose *)(self + 0x19);
        g.v = data_02041dc8;
        pg = (char *)&g;

        ((void **)self)[0xe2] = List_InsertSorted(self + 0x8b, 0x10, 100);
        {
            int *p = List_InsertSorted(self + 0x51, 4, 100);
            *((int **)self)[0xe2] = (int)Ov107_CloneResourceTransform(pg);
            r = Ov107_CloneResourceTransform(pg);
            *p = (int)r;
            self[0xe3] = (int)r;
        }
        Res_RequestIdPair(0x169);
    }
}
