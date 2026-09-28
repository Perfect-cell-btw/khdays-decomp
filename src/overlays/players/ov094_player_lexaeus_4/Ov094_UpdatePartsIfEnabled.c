/* While the character is shown, draws its five effect nodes (the matrix-driven one uploads the bone
 * matrices). */

extern void Ov094_DrawNodeWithOwnerPos2(int a, int b);
extern void Ov094_DrawNodeWithOwnerPos(int a, int b);
extern void Ov094_UploadBoneMatrices(int a, int b);
extern void Ov094_DrawNodeCallback(int a, int b);
extern void Ov094_DrawNodeAtOwner(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov094_UpdatePartsIfEnabled(int self, int a) {
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov094_DrawNodeWithOwnerPos2(self, a + 0x228);
    Ov094_DrawNodeWithOwnerPos(self, a);
    Ov094_UploadBoneMatrices(self, a + 0x118);
    Ov094_DrawNodeCallback(self, a + 0x338);
    Ov094_DrawNodeAtOwner(self, a + 0x444);
}
