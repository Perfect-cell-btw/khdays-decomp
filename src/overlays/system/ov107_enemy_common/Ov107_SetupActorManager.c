extern char *NNSi_FndGetCurrentRootHeap(void);
extern void Ov107_ClearGlobalCBB00(void);
extern void List_Init(char *p);
extern void StoreGlobalPtrArray4At0c(int slot, void *handler);
extern int Msg_OpenContainerAndReadHeader(void *name, int slot);
extern char *Ov107_Pillar_New(int size);
extern int Ov107_ContainerNode_New(void);
extern void Ov107_DispatchByType(void);
extern void Ov107_Scene_Tick(void);
extern char *gOv107ActorManager;
extern int gOv107MsDpPath;
extern int gOv107MsEcPath;
extern int gOv107MsMpPath;
extern int gOv107MsSharedEffectPath;

/* Sets the actor manager up: two render lists, the two input handlers, the four sprite sets and
 * the four 0xa00-byte actor pools, each tagged with its index. Returns the tick handler. */
void *Ov107_SetupActorManager(void) {
    char *self = NNSi_FndGetCurrentRootHeap();
    int i;
    char *slot;
    gOv107ActorManager = self;
    Ov107_ClearGlobalCBB00();
    List_Init(self + 4);
    List_Init(self + 0x4c);
    StoreGlobalPtrArray4At0c(1, (void *)&Ov107_DispatchByType);
    StoreGlobalPtrArray4At0c(4, (void *)&Ov107_DispatchByType);
    *(int *)(self + 0x7c) = Msg_OpenContainerAndReadHeader(&gOv107MsDpPath, 0xb);
    *(int *)(self + 0x80) = Msg_OpenContainerAndReadHeader(&gOv107MsEcPath, 0xb);
    *(int *)(self + 0x84) = Msg_OpenContainerAndReadHeader(&gOv107MsMpPath, 0xb);
    *(int *)(self + 0x88) = Msg_OpenContainerAndReadHeader(&gOv107MsSharedEffectPath, 0xb);
    i = 0;
    slot = self;
    do {
        char *pool = Ov107_Pillar_New(0xa << 8);
        *(char **)(slot + 0x2c) = pool;
        pool[0x6d << 2] = (char)i;
        i++;
        slot += 4;
    } while (i < 4);
    *(int *)self = Ov107_ContainerNode_New();
    *(int *)(self + 0x3c) = 1 << 0xc;
    *(int *)(self + 0x44) = 0;
    return (void *)&Ov107_Scene_Tick;
}
