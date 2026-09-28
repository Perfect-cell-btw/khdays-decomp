extern void Res_LoadSpriteSet(int *dst, int res, int a, int b, int c);
extern void Obj_RelocateSections(int res, int a);
extern int Archive_GetMember(int res, int a, int b);
extern int GetResourceSubBlock_CHAR2(int block, int *out);

/* Load a graphics resource block into *dst: when the context has a secondary
 * archive (+0x1dbc) prefer it, else fall back to the primary (+0x1db8). */
void Ov003_LoadCharResource(int *dst, int ctx, int a, int b, int c) {
    if (*(int *)(ctx + 0x1dbc) == 0) {
        Res_LoadSpriteSet(dst, *(int *)(ctx + 0x1db8), a, b, c);
        return;
    }
    Res_LoadSpriteSet(dst, *(int *)(ctx + 0x1db8), a, -1, c);
    Obj_RelocateSections(*(int *)(ctx + 0x1dbc), 0);
    if (b < 0) {
        return;
    }
    {
        int block = Archive_GetMember(*(int *)(ctx + 0x1dbc), 1, b);
        if (block == 0) {
            return;
        }
        if (GetResourceSubBlock_CHAR2(block, dst + 1) == 0) {
            dst[1] = 0;
        }
    }
}
