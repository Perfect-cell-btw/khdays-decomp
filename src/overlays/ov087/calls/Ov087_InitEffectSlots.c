extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov087_CreateSubObject(int a);
extern int data_ov087_020b9be0;
extern int data_ov087_020b9b78;

typedef struct { int w[5]; } Params;
extern Params data_ov087_020b9a24;

void Ov087_InitEffectSlots(int self) {
    int base = *(int *)&data_ov087_020b9be0;
    Params p;
    char *blk;
    *(signed char *)(base + 0x2000 + 0xcfc) = 0;
    blk = (char *)(base + 0xfc + 0x2c00);
    RegisterSeqAndInit((int)(blk + 4), &data_ov087_020b9b78, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov087_020b9a24;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
    Ov087_CreateSubObject(base);
}
