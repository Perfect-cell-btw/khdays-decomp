extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov055_OpenSecondarySubObjects(int p);
extern int data_ov055_020b7740;
extern int data_ov055_020b76c8;

void Ov055_InitGlobalRecordAndForward(void) {
    int d = data_ov055_020b7740;
    int base = d + 0x2d94;
    *(int *)(base + 0x14) = 0;
    RegisterSeqAndInit(base + 0x18, (int)&data_ov055_020b76c8, 1, *(unsigned char *)(d + 9) + 7);
    Ov055_OpenSecondarySubObjects(d);
}
