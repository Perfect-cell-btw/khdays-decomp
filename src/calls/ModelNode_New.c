extern void *CallocInstance(int);
extern void ModelNode_Init(void *);

void *ModelNode_New(void) {
    void *obj = CallocInstance(0xb4);
    ModelNode_Init(obj);
    return obj;
}
