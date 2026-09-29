/*
 * SpriteRes_Load - load a sprite resource archive for an object and upload its
 * palette. Opens archive `name` (kind 0xe) via Archive_LoadFile, stores it at
 * obj[7], then pulls members by kind: the character/cell block (kind 2 or 1
 * depending on the map-state flag), the CEBK cell bank (kind 3) and the extra
 * bank (kind 5), decoding each sub-block into the object's fields. Computes the
 * span/aligned-end via CountBlocksForSpan/ComputeAlignedEndOffset and advances the map-state
 * VRAM cursor at +0x4610. Finally, if a palette member (kind 0) exists, uploads
 * it with Pltt_Upload: the extended-palette path (dwUseExt) forces a 0x200 size,
 * uploads to slot +0x4616 and bumps the ext counters at +0x4618/+0x4616; the
 * plain path uploads to +0x461c and advances that cursor by the palette size.
 */
#pragma thumb on

typedef struct PlttUpload {
    unsigned int dwHandle;
    unsigned int dwUseExt;
    unsigned int dwSize;
    void *pData;
} PlttUpload;

extern int DispObjList_GetEngine(unsigned int mapState);
extern void *Archive_LoadFile(char *name, int kind);
extern void Obj_RelocateSections(void *arc, int kind);
extern int Archive_GetMember(int arc, int type, int idx);
extern void GetResourceSubBlock_CHAR(int member, unsigned short **out);
extern void NNS_G2dLoadImage1DMapping(unsigned short *hdr, unsigned int a, int mode, int *out);
extern void NNS_G2dGetUnpackedCellBank(int member, int *out);
extern void func_020116e4(int member, int *out);
extern unsigned int CountBlocksForSpan(unsigned int mapState, int obj);
extern unsigned int ComputeAlignedEndOffset(unsigned int mapState, int *obj);
extern void NNS_G2dGetUnpackedPaletteData(int member, PlttUpload **out);
extern void Pltt_Upload(PlttUpload *desc, int addr, int slot, int *out);

void SpriteRes_Load(unsigned int param_1, char *param_2, int *param_3)
{
    void *arc;
    int mode;
    int member;
    unsigned int span;
    unsigned short *charHdr;
    PlttUpload *pltt;

    DispObjList_GetEngine(param_1);
    arc = Archive_LoadFile(param_2, 0xe);
    param_3[7] = (int)arc;
    Obj_RelocateSections(arc, 1);
    mode = DispObjList_GetEngine(param_1);
    if (mode == 0)
        member = Archive_GetMember((int)arc, 2, 0);
    else
        member = Archive_GetMember((int)arc, 1, 0);
    GetResourceSubBlock_CHAR(member, &charHdr);
    *param_3 = *(int *)(charHdr + 8);
    param_3[1] = *(int *)(charHdr + 2);
    param_3[2] = *(int *)(charHdr + 4);
    NNS_G2dLoadImage1DMapping(charHdr, *(unsigned int *)(param_1 + 0x4610), mode, param_3 + 0xd);
    member = Archive_GetMember((int)arc, 3, 0);
    param_3[5] = member;
    member = Archive_GetMember((int)arc, 5, 0);
    param_3[6] = member;
    NNS_G2dGetUnpackedCellBank(param_3[5], param_3 + 3);
    func_020116e4(param_3[6], param_3 + 4);
    span = CountBlocksForSpan(param_1, (int)param_3);
    param_3[0x16] = span;
    span = ComputeAlignedEndOffset(param_1, param_3);
    *(unsigned int *)(param_1 + 0x4610) += span;
    *(short *)(param_3 + 0x18) = -1;
    member = Archive_GetMember((int)arc, 0, 0);
    if (member != 0) {
        NNS_G2dGetUnpackedPaletteData(member, &pltt);
        if (pltt->dwUseExt != 0) {
            pltt->dwSize = 0x200;
            Pltt_Upload(pltt, *(unsigned short *)(param_1 + 0x4616), mode, param_3 + 8);
            *(unsigned short *)(param_3 + 0x18) = *(unsigned short *)(param_1 + 0x4618);
            *(unsigned short *)(param_1 + 0x4618) += 1;
            *(unsigned short *)(param_1 + 0x4616) += 0x200;
            return;
        }
        Pltt_Upload(pltt, *(unsigned short *)(param_1 + 0x461c), mode, param_3 + 8);
        *(unsigned short *)(param_1 + 0x461c) += pltt->dwSize;
    }
}
