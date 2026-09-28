/* Ov008_SetupMenuSurface -- Ov008_SetupMenuSurface (108 B, 7 relocs).
 * Configures the primary menu surface (ctx+0x10) from a single style template. Copies the
 * 0x28-byte template data_ov008_0208f618 to a local, binds the cell table data_ov008_0209078c to
 * the list at ctx+4 (Ov008_VarTable_Load), overrides the template's field18
 * (Ov008_ResetEntry(9)) and field20 (Ov008_GetCtxBlock968c()), and applies it with TileSurface_InitAndUpload4bpp.
 * The one-surface counterpart of Ov008_SetupMenuSurfaces (Ov008_SetupMenuSurfaces). */
#include "nitro/types.h"

typedef struct Style28 {
    u8  pad_0000[0x18];
    int field18;        /* 0x18 */
    u8  pad_001c[4];
    int field20;        /* 0x20 */
    u8  pad_0024[4];
} Style28;

extern Style28 data_ov008_0208f618;
extern int  data_ov008_0209078c;
extern void *Ov008_GetMenuContext(void);
extern void Ov008_VarTable_Load(void *p, void *tbl);
extern int  Ov008_GetCtxBlock968c(void);
extern int  Ov008_ResetEntry(int a);
extern void TileSurface_InitAndUpload4bpp(void *dst, Style28 *src);

void Ov008_SetupMenuSurface(void)
{
    Style28 s = data_ov008_0208f618;
    char *ctx = (char *)Ov008_GetMenuContext();

    Ov008_VarTable_Load(ctx + 4, &data_ov008_0209078c);
    s.field20 = Ov008_GetCtxBlock968c();
    s.field18 = Ov008_ResetEntry(9);
    TileSurface_InitAndUpload4bpp(ctx + 0x10, &s);
}
