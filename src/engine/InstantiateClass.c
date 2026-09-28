extern void *data_0204c024;
extern void *AllocFromExpHeapWrapper(int size, void *heap);
extern void RunClassConstructor(void *ptr, int arg1, int arg2);

void InstantiateClass(int arg1, int arg2) {
    void *ptr = AllocFromExpHeapWrapper(0x2c, data_0204c024);

    RunClassConstructor(ptr, arg1, arg2);
}
