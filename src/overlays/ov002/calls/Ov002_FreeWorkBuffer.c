extern void NNSi_FndFreeFromDefaultHeap();
extern int data_ov002_0207fa0c;

void Ov002_FreeWorkBuffer(void) {
    int p = *(int *)&data_ov002_0207fa0c;
    if (p == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(p);
    data_ov002_0207fa0c = 0;
}
