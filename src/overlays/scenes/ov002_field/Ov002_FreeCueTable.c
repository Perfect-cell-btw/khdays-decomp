extern void NNSi_FndFreeFromDefaultHeap();
extern int data_ov002_0207f9f8;

void Ov002_FreeCueTable(void) {
    if (data_ov002_0207f9f8 != 0) {
        NNSi_FndFreeFromDefaultHeap(data_ov002_0207f9f8);
    }
    data_ov002_0207f9f8 = 0;
}
