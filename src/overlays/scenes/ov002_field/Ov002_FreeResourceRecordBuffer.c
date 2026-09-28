extern void NNSi_FndFreeFromDefaultHeap();

void Ov002_FreeResourceRecordBuffer(int arg0) {
    int p = *(int *)arg0;
    if (p != 0) {
        NNSi_FndFreeFromDefaultHeap(p);
    }
}
