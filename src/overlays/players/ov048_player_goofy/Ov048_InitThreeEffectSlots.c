/* Initialises the character's effect slots: clears their states, registers the three effect
 * sequences for the owner's palette slot and allocates its slot class. */

extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern int data_ov048_020b4b80;
extern int gOv048GoofyLiE1PackPath;
extern int gOv048GoofyLiE0PackPath;
extern int gOv048GoofyLiE3PackPath;

typedef struct { int w[5]; } Params;
extern Params data_ov048_020b4a8c;

void Ov048_InitThreeEffectSlots(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov048_020b4b80;
    blk = (char *)(base + 0x2c + 0x2c00);
    *(int *)(blk + 8) = 0;
    *(int *)(blk + 0x11c) = 0;
    RegisterSeqAndInit((int)(blk + 0x24c), &gOv048GoofyLiE1PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0xc), &gOv048GoofyLiE0PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x120), &gOv048GoofyLiE3PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov048_020b4a8c;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
}
