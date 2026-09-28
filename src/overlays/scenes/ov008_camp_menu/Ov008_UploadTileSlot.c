/* Ov008_UploadTileSlot -- Ov008_UploadTileSlot (156 B, 6 relocs).
 * Uploads tile slot arg1 (0x800 bytes) into the work buffer and, when arg2 != 0, draws it.
 * Copies 0x800 bytes from arg0->field2f0[arg1] to (Obj_GetWord18(arg0+0xac))->field20[arg1]
 * (both indexed by arg1 * 0x800) with MIi_CpuCopyFast. If arg2 == 0 it stops there. Otherwise,
 * when NNSi_G2dFontGetTextWidth(arg0->fieldcc, arg0->fieldd0, arg2) >= 0x52 it latches fieldcc to the
 * Ov008_GetDescriptor3 handle, renders via Text_DrawWithShadow(arg0+0xac, 0x14, arg1*16+3, arg3, arg2,
 * 1), and finally sets arg0->fieldcc to the Ov008_GetCtxBlock968c handle. */
extern char *Obj_GetWord18(void *p);
extern int   Ov008_GetCtxBlock968c(void);
extern int   Ov008_GetDescriptor3(void);
extern int   NNSi_G2dFontGetTextWidth(int a, int b, int c);
extern void  MIi_CpuCopyFast(const void *src, void *dst, unsigned int size);
extern void  Text_DrawWithShadow(void *surface, int a, int b, int c, int d, int e);

void Ov008_UploadTileSlot(void *arg0, int arg1, int arg2, int arg3)
{
    char *p = (char *)arg0;
    char *buf = Obj_GetWord18(p + 0xac);
    char *dst = *(char **)(buf + 0x20);
    int r4 = Ov008_GetCtxBlock968c();
    int newval = Ov008_GetDescriptor3();

    MIi_CpuCopyFast(*(char **)(p + 0x2f0) + arg1 * 0x800, dst + arg1 * 0x800, 0x800);
    if (arg2 == 0) {
        return;
    }
    if (NNSi_G2dFontGetTextWidth(*(int *)(p + 0xcc), *(int *)(p + 0xd0), arg2) >= 0x52) {
        *(int *)(p + 0xcc) = newval;
    }
    Text_DrawWithShadow(p + 0xac, 0x14, arg1 * 16 + 3, arg3, arg2, 1);
    *(int *)(p + 0xcc) = r4;
}
