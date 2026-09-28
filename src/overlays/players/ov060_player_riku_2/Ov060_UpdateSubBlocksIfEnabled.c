extern void Ov060_DrawNodeAtOwner(int a, int b);
extern void Ov060_DrawNodeCallback(int a, int b);
extern void Ov060_UploadBoneMatrices(int a, int b);
extern void Ov060_SetYawAndDrawNode(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov060_UpdateSubBlocksIfEnabled(int self, int blk) {
    int i;
    char *p;
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov060_DrawNodeAtOwner(self, blk);
    p = (char *)(blk + 0x330);
    for (i = 0; i < 3; i++, p += 0x110) {
        Ov060_DrawNodeCallback(self, (int)p);
    }
    Ov060_UploadBoneMatrices(self, blk + 0x110);
    Ov060_SetYawAndDrawNode(self, blk + 0x220);
}
