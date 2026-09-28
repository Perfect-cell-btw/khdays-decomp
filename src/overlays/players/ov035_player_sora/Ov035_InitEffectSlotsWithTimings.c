/* Initialises the character's effect slots: sets their timings, registers the effect sequence for
 * the owner's palette slot, allocates its slot class and sets up the channel blocks. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov035_SetupChannelBlocks(int self);
extern int data_ov035_020b4ca0;
extern int data_ov035_020b4c54;

typedef struct { int w[5]; } Params;
extern Params data_ov035_020b4b78;

void Ov035_InitEffectSlotsWithTimings(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov035_020b4ca0;
    blk = (char *)(base + 0xa4 + 0x2c00);
    *(int *)(blk + 0x10) = 0;
    *(int *)(blk + 0x124) = 0xf6;
    *(int *)(blk + 0x128) = 0x10a4;
    *(int *)(blk + 0x12c) = 0xccd;
    RegisterSeqAndInit((int)(blk + 0x14), &data_ov035_020b4c54, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov035_020b4b78;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
    Ov035_SetupChannelBlocks(self);
}
