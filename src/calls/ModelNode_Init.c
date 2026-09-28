extern void Node_BaseInit(void *p);
extern void List_Init(void *p);
extern void ModelNode_Destroy(void);
extern void invokeObjCallbackList(void);
extern void ProcessListChildren(void);
extern void ModelNode_UpdateTree(void);
extern void ForEachChildDispatch(void);

struct S {
    char _0[0x64];
    void (*x64)(void);
    void (*x68)(void);
    void (*x6c)(void);
    char _70[0x7c - 0x70];
    void (*x7c)(void);
    void (*x80)(void);
};

void ModelNode_Init(struct S *p)
{
    Node_BaseInit(p);
    p->x64 = ModelNode_Destroy;
    p->x7c = invokeObjCallbackList;
    p->x80 = ProcessListChildren;
    List_Init((char *)p + 0x88);
    p->x68 = ModelNode_UpdateTree;
    p->x6c = ForEachChildDispatch;
}
