extern void NNSi_FndFreeFromDefaultHeap(void *);
extern int data_0204caac;

void FreeInstanceMemory(void *p) {
    if (p == 0) return;
    data_0204caac -= 1;
    NNSi_FndFreeFromDefaultHeap(p);
}
