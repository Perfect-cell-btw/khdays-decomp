/* Load a background set from the archive owned by `page`: pull members 0, 1 and
 * 6 (palette, character data, screen map), push all three to the sub screen's
 * BG3, then close the archive and release the page. Finally raise the context's
 * pending event -- through the hook at +0x1a8 when one is installed, otherwise
 * Ov002_RetargetSceneTween -- and park the context state at 2. */
extern int data_ov002_0207f9fc;

extern int Ov002_GetWord8(int page);
extern void Obj_RelocateSections(int arc, int a);
extern int Archive_GetMember(int arc, int member, int a);
extern int NNS_G2dGetUnpackedPaletteData(int block, void *out);
extern int GetResourceSubBlock_CHAR(int block, void *out);
extern int NNS_G2dGetUnpackedScreenData(int block, void *out);
extern void GXS_LoadBGPltt(void *src, int offset, unsigned int size);
extern void GXS_LoadBG3Char(void *src, int offset, unsigned int size);
extern void GXS_LoadBG3Scr(void *src, int offset, unsigned int size);
extern void ResGroup_Release(int arc);
extern void Ov002_DestroyOwnedEntry(int page, int a);
extern void Ov002_RetargetSceneTween(int arg, int a);

void Ov002_LoadBackgroundSet(int page) {
    int *chr;
    int *scr;
    int *pltt;
    char *ctx = *(char **)&data_ov002_0207f9fc;
    int arc = Ov002_GetWord8(page);

    Obj_RelocateSections(arc, 1);
    NNS_G2dGetUnpackedPaletteData(Archive_GetMember(arc, 0, 0), &pltt);
    GetResourceSubBlock_CHAR(Archive_GetMember(arc, 1, 0), &chr);
    NNS_G2dGetUnpackedScreenData(Archive_GetMember(arc, 6, 0), &scr);

    GXS_LoadBGPltt((void *)pltt[3], 0, pltt[2]);
    GXS_LoadBG3Char((void *)chr[5], 0, chr[4]);
    GXS_LoadBG3Scr((char *)scr + 0xc, 0, scr[2]);

    ResGroup_Release(arc);
    Ov002_DestroyOwnedEntry(page, 1);

    if (*(int *)(ctx + 0x24) != 0) {
        void (*hook)(int, int) = *(void (**)(int, int))(ctx + 0x1a8);

        if (hook == 0) {
            Ov002_RetargetSceneTween(0xffff0000, 0);
        } else {
            hook(0xffff0000, 0);
        }
        *(int *)(ctx + 0x28) = 2;
    }
}
