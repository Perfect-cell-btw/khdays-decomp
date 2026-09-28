/* While the character is shown, draws its five effect nodes (the matrix-driven one uploads the bone
 * matrices). */

extern void Ov057_DrawNodeWithOwnerPos2(int a, int b);
extern void Ov057_DrawNodeWithOwnerPos(int a, int b);
extern void Ov057_UploadBoneMatrices(int a, int b);
extern void Ov057_DrawNodeCallback(int a, int b);
extern void Ov057_DrawNodeAtOwner(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov057_UpdatePartsIfEnabled(int self, int a) {
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov057_DrawNodeWithOwnerPos2(self, a + 0x228);
    Ov057_DrawNodeWithOwnerPos(self, a);
    Ov057_UploadBoneMatrices(self, a + 0x118);
    Ov057_DrawNodeCallback(self, a + 0x338);
    Ov057_DrawNodeAtOwner(self, a + 0x444);
}
