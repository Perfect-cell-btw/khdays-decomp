extern void Ov038_DrawNodeWithOwnerPos2(int a, int b);
extern void Ov038_DrawNodeWithOwnerPos(int a, int b);
extern void Ov038_UploadBoneMatrices(int a, int b);
extern void Ov038_DrawNodeCallback(int a, int b);
extern void Ov038_DrawNodeAtOwner(int a, int b);

typedef struct { unsigned char b0 : 1; } Flags;

void Ov038_UpdatePartsIfEnabled(int self, int a) {
    if (!((Flags *)(self + 0x694))->b0) return;
    Ov038_DrawNodeWithOwnerPos2(self, a + 0x228);
    Ov038_DrawNodeWithOwnerPos(self, a);
    Ov038_UploadBoneMatrices(self, a + 0x118);
    Ov038_DrawNodeCallback(self, a + 0x338);
    Ov038_DrawNodeAtOwner(self, a + 0x444);
}
