extern int Ov025_FreeResourceRecordBuffer();
extern int Ov025_DestroyAllListObjects_2();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov025_DestroyMissionList(int arg0) {
    Ov025_FreeResourceRecordBuffer(arg0);
    Ov025_DestroyAllListObjects_2(arg0);
    int p = *(int *)(arg0 + 0x14);
    if (p == 0) {
        return;
    }
    NNSi_FndFreeFromDefaultHeap(p);
    *(int *)(arg0 + 0x14) = 0;
}
