extern void Ov041_DrawNodeAtOwner(int a, int b);
extern void Ov041_DrawNodeCallback(int a, int b);
extern void Ov041_UploadBoneMatrices(int a, int b);
extern void Ov041_SetYawAndDrawNode(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov041_UpdateSubBlocksIfEnabled(int self, int blk) {
    int i;
    char *p;
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov041_DrawNodeAtOwner(self, blk);
    p = (char *)(blk + 0x330);
    for (i = 0; i < 3; i++, p += 0x110) {
        Ov041_DrawNodeCallback(self, (int)p);
    }
    Ov041_UploadBoneMatrices(self, blk + 0x110);
    Ov041_SetYawAndDrawNode(self, blk + 0x220);
}
