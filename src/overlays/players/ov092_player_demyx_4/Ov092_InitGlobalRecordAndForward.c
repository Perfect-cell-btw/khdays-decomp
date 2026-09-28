extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov092_OpenSecondarySubObjects(int p);
extern int data_ov092_020bc4e0;
extern int data_ov092_020bc468;

void Ov092_InitGlobalRecordAndForward(void) {
    int d = data_ov092_020bc4e0;
    int base = d + 0x2d94;
    *(int *)(base + 0x14) = 0;
    RegisterSeqAndInit(base + 0x18, (int)&data_ov092_020bc468, 1, *(unsigned char *)(d + 9) + 7);
    Ov092_OpenSecondarySubObjects(d);
}
