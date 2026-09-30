/* Clears seven counters in the ov057 scene block, registers its five sequence
 * objects from the E0/E1/E2/E4/E5 resource paths, then initializes actor slot 5
 * from the shared five-word slot parameter block. */
extern void RegisterSeqAndInit(int a, void *b, int c, int d);
extern void Ov022_AllocateSlotWithClass(int a, int b, int c, void *d);
extern int data_ov057_020b74a0;
extern int gOv057LexaeusLiE0PackPath;
extern int gOv057LexaeusLiE1PackPath;
extern int gOv057LexaeusLiE2PackPath;
extern int gOv057LexaeusLiE4PackPath;
extern int gOv057LexaeusLiE5PackPath;

typedef struct { char *pszResourcePath; int resourceKind; int reserved[3]; } Ov022SlotInitParams;
extern Ov022SlotInitParams data_ov057_020b738c;

void Ov057_ResetSequences(int self) {
    Ov022SlotInitParams params;
    char *blk;
    int base = *(int *)&data_ov057_020b74a0;
    blk = (char *)(base + 0x2c + 0x2c00);
    *(int *)(blk + 0x228) = 0;
    *(int *)(blk + 0xc) = 0;
    *(int *)(blk + 0x118) = 0;
    *(int *)(blk + 0x338) = 0;
    *(int *)(blk + 0x444) = 0;
    *(int *)(blk + 8) = 0;
    *(int *)(blk + 0x550) = 0;
    RegisterSeqAndInit((int)(blk + 0x22c), &gOv057LexaeusLiE0PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x10), &gOv057LexaeusLiE1PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x11c), &gOv057LexaeusLiE2PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x33c), &gOv057LexaeusLiE4PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    RegisterSeqAndInit((int)(blk + 0x448), &gOv057LexaeusLiE5PackPath, 1,
                  *(unsigned char *)(base + 9) + 7);
    params = data_ov057_020b738c;
    Ov022_AllocateSlotWithClass(self + 0x248 + 0x2400, *(unsigned char *)(self + 9), 5, &params);
}
