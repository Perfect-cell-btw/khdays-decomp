extern void RegisterSeqAndInit(int a, int b, int c, int d);
extern void Ov083_BuildEmitterDescriptor(int p);
extern int data_ov083_020b9ad4;

void Ov083_InitActorTwoRegionsAndForward(int this_) {
    char *a = (char *)(this_ + 0x2000);
    char *b = (char *)(this_ + 0x2df0);
    *(unsigned char *)(a + 0xdf0) = 0;
    *(int *)(b + 0x114) = 0;
    RegisterSeqAndInit((int)(b + 4), (int)&data_ov083_020b9ad4, 1, *(unsigned char *)(this_ + 9) + 7);
    Ov083_BuildEmitterDescriptor(this_);
}
