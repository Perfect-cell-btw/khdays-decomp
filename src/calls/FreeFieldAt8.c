extern int NNSi_FndFreeFromDefaultHeap();

void FreeFieldAt8(int *p) {
    int a = p[2];
    if (a) {
        NNSi_FndFreeFromDefaultHeap(a);
    }
}
