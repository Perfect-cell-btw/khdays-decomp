/* Resets the five animation slots of the ov077 scene block and re-arms them
 * from their five descriptors, then hands the shared parameter block to the
 * actor's own slot. Same routine as the matched overlay siblings with five slots
 * rather than three and two extra counters cleared. */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern int data_ov077_020b9b80;
extern int gOv077LexaeusLiE0PackPath;
extern int gOv077LexaeusLiE1PackPath;
extern int gOv077LexaeusLiE2PackPath;
extern int gOv077LexaeusLiE4PackPath;
extern int gOv077LexaeusLiE5PackPath;

typedef struct { int w[5]; } Params;
extern Params data_ov077_020b9a6c;

void Ov077_InitSceneResources(int self) {
    Params p;
    char *blk;
    int base = *(int *)&data_ov077_020b9b80;
    blk = (char *)(base + 0x2c + 0x2c00);
    *(int *)(blk + 0x228) = 0;
    *(int *)(blk + 0xc) = 0;
    *(int *)(blk + 0x118) = 0;
    *(int *)(blk + 0x338) = 0;
    *(int *)(blk + 0x444) = 0;
    *(int *)(blk + 8) = 0;
    *(int *)(blk + 0x550) = 0;
    RegisterSeqAndInit((int)(blk + 0x22c), &gOv077LexaeusLiE0PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x10), &gOv077LexaeusLiE1PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x11c), &gOv077LexaeusLiE2PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x33c), &gOv077LexaeusLiE4PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x448), &gOv077LexaeusLiE5PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    p = data_ov077_020b9a6c;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &p);
}
