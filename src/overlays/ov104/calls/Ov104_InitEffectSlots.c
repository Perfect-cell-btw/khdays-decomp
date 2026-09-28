extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov104_CreateSubObject(int a);
extern int data_ov104_020bc2a0;
extern int data_ov104_020bc238;

typedef struct { int w[5]; } Params;
extern Params data_ov104_020bc0e4;

void Ov104_InitEffectSlots(int self) {
    int base = *(int *)&data_ov104_020bc2a0;
    Params p;
    char *blk;
    *(signed char *)(base + 0x2000 + 0xcfc) = 0;
    blk = (char *)(base + 0xfc + 0x2c00);
    RegisterSeqAndInit((int)(blk + 4), &data_ov104_020bc238, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov104_020bc0e4;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
    Ov104_CreateSubObject(base);
}
