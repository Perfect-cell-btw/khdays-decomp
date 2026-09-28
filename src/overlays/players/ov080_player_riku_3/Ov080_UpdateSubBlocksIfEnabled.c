/* While the character is shown, draws its effect nodes: the one at the owner, the three emitters,
 * the matrix-driven one and the anchored one. */

extern void Ov080_DrawNodeAtOwner(int a, int b);
extern void Ov080_DrawNodeCallback(int a, int b);
extern void Ov080_UploadBoneMatrices(int a, int b);
extern void Ov080_SetYawAndDrawNode(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov080_UpdateSubBlocksIfEnabled(int self, int blk) {
    int i;
    char *p;
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov080_DrawNodeAtOwner(self, blk);
    p = (char *)(blk + 0x330);
    for (i = 0; i < 3; i++, p += 0x110) {
        Ov080_DrawNodeCallback(self, (int)p);
    }
    Ov080_UploadBoneMatrices(self, blk + 0x110);
    Ov080_SetYawAndDrawNode(self, blk + 0x220);
}
