extern void NNSi_FndFreeFromDefaultHeap();

void Ov002_FreeFieldAt8(int arg0) {
    int p = *(int *)(arg0 + 8);
    if (p != 0) {
        NNSi_FndFreeFromDefaultHeap(p);
    }
}
