/* Class initialiser: installs the actor's handler table, seeds its two motion
   pairs, builds the render object, opens four subitem channels and links two
   sorted list entries built from the seeded block at +0x64. */

extern void Ov285_OnDespawn(void), Ov285_CopyBlockToTwoNodes(void);
extern void Ov285_CreateRegistryEntryAndLink(void), Ov285_SpendHitPointsOnHit(void);
extern void Ov285_TryBeginSubState5IfIdle(void), Ov285_ForwardAnimEvent(void);

extern void *Ov107_PackTextureHandle();
extern void *CreateSubitemInstance0xB4();
extern void RegisterSubscriberSlot();
extern void Ov107_Actor_SetAttachSlot();
extern void *List_InsertSorted();
extern long long Ov107_CloneResourceTransform();

void Ov285_ClassInit(int param_1)
{
    *(void **)(param_1 + 8) = Ov285_OnDespawn;
    *(void **)(param_1 + 0xc) = Ov285_CopyBlockToTwoNodes;
    *(void **)(param_1 + 0x30) = Ov285_CreateRegistryEntryAndLink;
    *(void **)(param_1 + 0x1d0) = Ov285_SpendHitPointsOnHit;
    *(void **)(param_1 + 0x1e0) = Ov285_TryBeginSubState5IfIdle;
    *(void **)(param_1 + 0x1dc) = Ov285_ForwardAnimEvent;
    *(int *)(param_1 + 0x70) = 0xc00;
    *(int *)(param_1 + 0x64) = 0;
    *(int *)(param_1 + 0x68) = 0xc00;
    *(int *)(param_1 + 0x6c) = 0;
    *(void **)(param_1 + 0x384) = CreateSubitemInstance0xB4(Ov107_PackTextureHandle(param_1, 0));
    RegisterSubscriberSlot(*(int *)(param_1 + 0x9c), *(void **)(param_1 + 0x384));
    Ov107_Actor_SetAttachSlot(param_1, 0, 1, 0, 0x1f33);
    Ov107_Actor_SetAttachSlot(param_1, 1, 1, 0, 0x1f33);
    Ov107_Actor_SetAttachSlot(param_1, 2, 1, 0, 0x1f33);
    Ov107_Actor_SetAttachSlot(param_1, 4, 1, 0, 0x1f33);
    *(void **)(param_1 + 0x38c) = List_InsertSorted(param_1 + 0x22c, 0x10, 100);
    **(int **)(param_1 + 0x38c) = (int)Ov107_CloneResourceTransform(param_1 + 0x64);
    {
        int *p = List_InsertSorted(param_1 + 0x144, 4, 100);
        int r = (int)Ov107_CloneResourceTransform(param_1 + 0x64);
        *p = r;
        *(int *)(param_1 + 0x388) = r;
    }
}
