extern int func_0201696c();
extern void ResSlot_Release(int a);
extern void ResSlot_ReleaseResource(void);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern int NNSi_FndGetAllocatorForDefaultHeap(int a);

void FreeAllResourceTables(int *p) {
    int i, j;
    int last = 0;
    for (i = 4; i >= 0; i--) {
        for (j = ((short *)p)[i] - 1; j >= 0; j--) {
            func_0201696c(NNSi_FndGetAllocatorForDefaultHeap(0), ((int *)p[i + 4])[j]);
        }
        if (p[i + 4]) last = p[i + 4];
    }
    if (last) NNSi_FndFreeFromDefaultHeap(last);
    if (p[3]) {
        ResSlot_ReleaseResource();
        ResSlot_Release(p[3]);
    }
    p[3] = 0;
}
