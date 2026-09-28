extern void *CallocInstance(int size);
extern void ModelObj_Construct(void *self, void *arg);

void *CreateSubitemInstance0xB4(void *arg0) {
    void *p = CallocInstance(0xb4);
    ModelObj_Construct(p, arg0);
    return p;
}
