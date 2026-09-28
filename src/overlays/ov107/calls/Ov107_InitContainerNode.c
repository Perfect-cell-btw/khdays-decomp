/* Constructs a container-type AI node: base behaviour init, set flags bit 4 and vtable slot bit 1,
 * install three callbacks, allocate and init a 0x28-byte child list at +0xb0, clear the tracking
 * fields, and attach a fresh object at +0x3c. */

typedef unsigned short u16;

extern void Ov107_InitBehaviorNode(u16 *node);
extern void *CallocInstance(int size);
extern void List_Init(void *list);
extern void *ObjList_New(void);
extern void Ov107_Scene_Destroy(void);
extern void Ov107_ContainerNode_Tick(void);
extern void Ov107_FaceReferenceDirection(void);

void Ov107_InitContainerNode(u16 *node) {
    Ov107_InitBehaviorNode(node);
    *node |= 0x10;
    *(void **)(node + 4) = (void *)Ov107_Scene_Destroy;
    *(void **)(node + 6) = (void *)Ov107_ContainerNode_Tick;
    *(void **)(node + 8) = (void *)Ov107_FaceReferenceDirection;
    *(unsigned int *)(node + 0x20) |= 2;
    *(void **)(node + 0x58) = CallocInstance(0x28);
    List_Init(*(void **)(node + 0x58));
    *(int *)((char *)node + 0xac) = 0;
    *(int *)((char *)node + 0x94) = 0;
    *(int *)((char *)node + 0x9c) = 0;
    *(int *)((char *)node + 0xa0) = 0;
    *(void **)(node + 0x1e) = ObjList_New();
}
