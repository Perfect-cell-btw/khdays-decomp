/* While the character is shown, draws its five effect nodes (the matrix-driven one uploads the bone
 * matrices). */

extern void Ov077_DrawNodeWithOwnerPos2(int a, int b);
extern void Ov077_DrawNodeWithOwnerPos(int a, int b);
extern void Ov077_UploadBoneMatrices(int a, int b);
extern void Ov077_DrawNodeCallback(int a, int b);
extern void Ov077_DrawNodeAtOwner(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov077_UpdatePartsIfEnabled(int self, int a) {
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov077_DrawNodeWithOwnerPos2(self, a + 0x228);
    Ov077_DrawNodeWithOwnerPos(self, a);
    Ov077_UploadBoneMatrices(self, a + 0x118);
    Ov077_DrawNodeCallback(self, a + 0x338);
    Ov077_DrawNodeAtOwner(self, a + 0x444);
}
