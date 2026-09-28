/* Initialises the character's effect slots: clears its state, registers the two effect sequences
 * for the owner's palette slot and allocates its slot class. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern int data_ov056_020b7620;
extern int data_ov056_020b75f4;
extern int data_ov056_020b7608;

typedef struct { int w[5]; } Params;
extern Params data_ov056_020b7510;

void Ov056_InitEffectSlotsAlt(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov056_020b7620;
    *(int *)(base + 0x2000 + 0xc2c) = 0;
    blk = (char *)(base + 0x2c + 0x2c00);
    RegisterSeqAndInit((int)(blk + 4), &data_ov056_020b75f4, 1, *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x120), &data_ov056_020b7608, 1, *(unsigned char *)(base + 9) + 7);
    p = data_ov056_020b7510;
    p.w[1] = 4;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
}
