/*
 * Res_LoadSpriteSet - load a 2D sprite resource set (screen / character / palette)
 * from an archive into a 3-pointer SpriteResSet.
 *
 * Opens the archive (Obj_RelocateSections), then for each of the three slots looks up an
 * archive member by kind and index -- kind 6 (NRCS screen) at scrIdx, kind 1
 * (NCGR character) at charIdx, kind 0 (PLTT palette) at pltIdx -- and decodes it
 * into the matching output pointer. A negative index, a missing member, or a
 * decoder that returns 0 leaves that pointer NULL.
 */

extern void Obj_RelocateSections(int *arc, int a, int b, int c);
extern int Archive_GetMember(int arc, int type, int idx);
extern int NNS_G2dGetUnpackedScreenData(int member, void *out);
extern int GetResourceSubBlock_CHAR2(int member, void *out);
extern int NNS_G2dGetUnpackedPaletteData(int member, void *out);

void Res_LoadSpriteSet(void *pArg1, void *pArg2, int param_3, int param_4, int param_5)
{
    unsigned int *param_1 = (unsigned int *)pArg1;
    int *param_2 = (int *)pArg2;
    int m;

    Obj_RelocateSections(param_2, 0, param_3, param_4);
    param_1[0] = 0;
    if (param_3 >= 0 && (m = Archive_GetMember((int)param_2, 6, param_3)) != 0 && NNS_G2dGetUnpackedScreenData(m, param_1) == 0)
        param_1[0] = 0;
    param_1[1] = 0;
    if (param_4 >= 0 && (m = Archive_GetMember((int)param_2, 1, param_4)) != 0 && GetResourceSubBlock_CHAR2(m, param_1 + 1) == 0)
        param_1[1] = 0;
    param_1[2] = 0;
    if (param_5 >= 0) {
        m = Archive_GetMember((int)param_2, 0, param_5);
        if (m != 0) {
            if (NNS_G2dGetUnpackedPaletteData(m, param_1 + 2) == 0)
                param_1[2] = 0;
        }
    }
}
