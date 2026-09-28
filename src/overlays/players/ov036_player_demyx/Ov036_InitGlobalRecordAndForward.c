extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov036_OpenSecondarySubObjects(int p);
extern int data_ov036_020b4f40;
extern int data_ov036_020b4ec8;

void Ov036_InitGlobalRecordAndForward(void) {
    int d = data_ov036_020b4f40;
    int base = d + 0x2d94;
    *(int *)(base + 0x14) = 0;
    RegisterSeqAndInit(base + 0x18, (int)&data_ov036_020b4ec8, 1, *(unsigned char *)(d + 9) + 7);
    Ov036_OpenSecondarySubObjects(d);
}
