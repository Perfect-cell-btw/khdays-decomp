extern void Ov097_DrawNodeAtOwner(int a, int b);
extern void Ov097_DrawNodeCallback(int a, int b);
extern void Ov097_UploadBoneMatrices(int a, int b);
extern void Ov097_SetYawAndDrawNode(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov097_UpdateSubBlocksIfEnabled(int self, int blk) {
    int i;
    char *p;
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov097_DrawNodeAtOwner(self, blk);
    p = (char *)(blk + 0x330);
    for (i = 0; i < 3; i++, p += 0x110) {
        Ov097_DrawNodeCallback(self, (int)p);
    }
    Ov097_UploadBoneMatrices(self, blk + 0x110);
    Ov097_SetYawAndDrawNode(self, blk + 0x220);
}
