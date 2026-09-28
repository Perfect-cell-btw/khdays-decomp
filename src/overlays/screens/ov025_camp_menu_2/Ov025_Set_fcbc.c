extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_Set_fcbc(int arg0) {
    int p = *(int *)(arg0 + 0x58);
    if (p == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(p);
    *(int *)(arg0 + 0x58) = 0;
}
