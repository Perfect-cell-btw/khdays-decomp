/* Frees a resource set: releases every resource of its five tables (last to first), frees the
 * tables' storage and releases its resource slot. */

extern int func_0201696c();
extern void ResSlot_Release(int a);
extern int ResSlot_ReleaseResource(void *slot);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern int NNSi_FndGetAllocatorForDefaultHeap(int a);

void FreeAllResourceTables(char *pP) {
    int *p = (int *)pP;
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
        ResSlot_ReleaseResource((void *)p[3]);
        ResSlot_Release(p[3]);
    }
    p[3] = 0;
}
