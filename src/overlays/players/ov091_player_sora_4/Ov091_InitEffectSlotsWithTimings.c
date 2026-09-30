/* Initialises the character's effect slots: sets their timings, registers the effect sequence for
 * the owner's palette slot, allocates its slot class and sets up the channel blocks. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern void Ov091_SetupChannelBlocks(int self);
extern int data_ov091_020bc240;
extern int gOv091SoraLiE0PackPath;

typedef struct { int w[5]; } Params;
extern Params data_ov091_020bc118;

void Ov091_InitEffectSlotsWithTimings(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov091_020bc240;
    blk = (char *)(base + 0xa4 + 0x2c00);
    *(int *)(blk + 0x10) = 0;
    *(int *)(blk + 0x124) = 0xf6;
    *(int *)(blk + 0x128) = 0x10a4;
    *(int *)(blk + 0x12c) = 0xccd;
    RegisterSeqAndInit((int)(blk + 0x14), &gOv091SoraLiE0PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov091_020bc118;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
    Ov091_SetupChannelBlocks(self);
}
