extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov075_OpenSecondarySubObjects(int p);
extern int data_ov075_020b9e20;
extern int data_ov075_020b9da8;

void Ov075_InitGlobalRecordAndForward(void) {
    int d = data_ov075_020b9e20;
    int base = d + 0x2d94;
    *(int *)(base + 0x14) = 0;
    RegisterSeqAndInit(base + 0x18, (int)&data_ov075_020b9da8, 1, *(unsigned char *)(d + 9) + 7);
    Ov075_OpenSecondarySubObjects(d);
}
