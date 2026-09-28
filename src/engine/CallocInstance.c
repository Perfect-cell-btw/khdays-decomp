extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int size);
extern void MI_CpuFill8(void *dst, unsigned char val, unsigned int size);

extern int data_0204caac;

void *CallocInstance(unsigned int size) {
    void *p = NNSi_FndAllocFromDefaultExpHeap(size);
    data_0204caac++;
    MI_CpuFill8(p, 0, size);
    return p;
}
