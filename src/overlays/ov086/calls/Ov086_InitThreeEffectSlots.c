extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern int data_ov086_020b9a60;
extern int data_ov086_020b9a14;
extern int data_ov086_020b9a28;
extern int data_ov086_020b9a3c;

typedef struct { int w[5]; } Params;
extern Params data_ov086_020b996c;

void Ov086_InitThreeEffectSlots(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov086_020b9a60;
    blk = (char *)(base + 0x2c + 0x2c00);
    *(int *)(blk + 8) = 0;
    *(int *)(blk + 0x11c) = 0;
    RegisterSeqAndInit((int)(blk + 0x24c), &data_ov086_020b9a14, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0xc), &data_ov086_020b9a28, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x120), &data_ov086_020b9a3c, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov086_020b996c;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
}
