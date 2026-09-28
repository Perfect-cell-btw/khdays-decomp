extern int NNSi_FndGetCurrentRootHeap(void);
extern void FreeAllResourceTables(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern void Ov002_FreeResourceTables(int a, int b);
extern void Ov082_setupTriple(int a);
extern void Ov022_DestroyRoot(int a);
extern unsigned char data_0204c240;
extern int data_ov082_020ba500;

void Ov082_ShutdownAndFree(void) {
    int base = NNSi_FndGetCurrentRootHeap();
    if ((data_0204c240 & 4) == 0) {
        FreeAllResourceTables(base + 0x2c2c);
        NNSi_FndFreeFromDefaultHeap(*(int *)(base + 0x2c50));
    }
    Ov002_FreeResourceTables(base + 0x2c54, base + 0x910);
    Ov082_setupTriple(base + 0x2ca8);
    Ov022_DestroyRoot(base);
    data_ov082_020ba500 = 0;
}
