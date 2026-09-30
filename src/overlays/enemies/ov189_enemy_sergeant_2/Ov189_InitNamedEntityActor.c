/* ov189 actor: install the handler table, set the bounding box, resolve the twelve bone
 * handles and open the four sub-items.
 *
 * The six words at +0x1fc are a bounding box, a pair of Vec3 holding the minimum and the
 * maximum, not six unrelated numbers: the matched Ov234_InitEffectActor in the same family
 * carries the identical shape at the identical offset with the identical three addends
 * 0x1dd3, 0x1c27 and 0xd64, and models it as min and max of a box. Same family as the matched ov188 constructor, written in its idioms:
 * the subitem is created as CreateSubitemInstance0xB4(Ov107_PackTextureHandle(...)) in one expression, the
 * bone handles come back from InsertSortedEntryWithKey with a literal 1 in the middle, and the two
 * stack blocks are whole-struct assignments rather than field-by-field stores. */
struct v3 { int a, b, c; };
struct Box { struct v3 min, max; };
struct Pose { struct v3 v; int nScale; };

extern struct v3 data_02041dc8;

extern unsigned short gOv189Bip01Name[];
extern unsigned short gOv189Bone01Name[];
extern unsigned short gOv189BoneHeadName[];
extern unsigned short gOv189Bip01PelvisName[];
extern unsigned short gOv189BoneLUpperArmName[];
extern unsigned short gOv189BoneLFingName[];
extern unsigned short gOv189BoneRUpperArmName[];
extern unsigned short gOv189BoneRFingName[];
extern unsigned short gOv189Bip01LThighName[];
extern unsigned short gOv189Bip01LFootName[];
extern unsigned short gOv189Bip01RThighName[];
extern unsigned short gOv189Bip01RFootName[];
extern int gOv189MoveName;

extern void Ov189_ReleaseSubObjectsAndSlotArrayThenNotify(void), Ov189_TickWithChildRefresh(void), Ov189_HandleSubitemCommand(void);
extern void Ov189_SpawnActorRegistryEntry(void), func_ov189_020d0270(void), func_ov189_020d027c(void);
extern void Ov189_ReleaseByStateAndPublishPose(void), Ov189_HandleHitEvent(void), Ov189_Model_ReapplyTrack0(void);
extern void Ov189_RequestSubState10IfNotCurrent(void), Ov189_RequestSubState11IfIdle(void);

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

void Ov189_InitNamedEntityActor(int param_1) {
    struct Box box;
    struct Pose g;
    char *pg;
    void *sub;
    long long r;

    box.min.a = -0xeea;
    box.min.b = 0x17;
    box.min.c = -0x858;
    box.max.a = box.min.a + 0x1dd3;
    box.max.b = box.min.b + 0x1c27;
    box.max.c = box.min.c + 0xd64;
    *(void **)(((unsigned int)param_1) + 8) = Ov189_ReleaseSubObjectsAndSlotArrayThenNotify;
    *(void **)(((unsigned int)param_1) + 0xc) = Ov189_TickWithChildRefresh;
    *(void **)(((unsigned int)param_1) + 0x1c) = Ov189_HandleSubitemCommand;
    *(void **)(((unsigned int)param_1) + 0x30) = Ov189_SpawnActorRegistryEntry;
    *(void **)(((unsigned int)param_1) + 0x28) = func_ov189_020d0270;
    *(void **)(((unsigned int)param_1) + 0x2c) = func_ov189_020d027c;
    *(void **)(((unsigned int)param_1) + 0x34) = Ov189_ReleaseByStateAndPublishPose;
    *(void **)(((unsigned int)param_1) + 0x1d0) = Ov189_HandleHitEvent;
    *(void **)(((unsigned int)param_1) + 0x1dc) = Ov189_Model_ReapplyTrack0;
    *(void **)(((unsigned int)param_1) + 0x1e0) = Ov189_RequestSubState10IfNotCurrent;
    *(void **)(((unsigned int)param_1) + 0x1e4) = Ov189_RequestSubState11IfIdle;
    *(int *)(((unsigned int)param_1) + 0x70) = 0x1000;
    *(int *)(((unsigned int)param_1) + 0x64) = 0;
    *(int *)(((unsigned int)param_1) + 0x68) = 0x1000;
    *(int *)(((unsigned int)param_1) + 0x6c) = 0;

    *(struct Box *)(((unsigned int)param_1) + 0x1fc) = box;

    *(void **)(((unsigned int)param_1) + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(((unsigned int)param_1), 0));
    int *self = (int *)param_1;
    RegisterSubscriberSlot(self[0x27], ((void **)self)[0xe1]);
    ((void **)self)[0xe4] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01Name);
    ((void **)self)[0xe5] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bone01Name);
    ((void **)self)[0xe6] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189BoneHeadName);
    ((void **)self)[0xe7] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01PelvisName);
    ((void **)self)[0xe8] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189BoneLUpperArmName);
    ((void **)self)[0xe9] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189BoneLFingName);
    ((void **)self)[0xea] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189BoneRUpperArmName);
    ((void **)self)[0xeb] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189BoneRFingName);
    ((void **)self)[0xec] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01LThighName);
    ((void **)self)[0xed] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01LFootName);
    ((void **)self)[0xee] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01RThighName);
    ((void **)self)[0xef] = InsertSortedEntryWithKey(self[0xe1], 1, gOv189Bip01RFootName);

    ((void **)self)[0xf0] =
        Ov107_CreateNamedResourceBinding(Ov107_PackTextureHandle(self, 1), &gOv189MoveName);

    Ov107_Actor_SetAttachSlot(self, 0, 1, 0, 0x2000);
    Ov107_Actor_SetAttachSlot(self, 2, 1, 0, 0x1500);
    Ov107_Actor_SetAttachSlot(self, 1, 1, 0, 0x1500);
    Ov107_Actor_SetAttachSlot(self, 4, 1, 0, 0x1500);

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
    Res_RequestIdPair(0x12f);
}


