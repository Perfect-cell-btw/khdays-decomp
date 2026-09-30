/* Ov025_SetupMenuSurface -- Ov008_SetupMenuSurface (108 B, 7 relocs).
 * Configures the primary menu surface (ctx+0x10) from a single style template. Copies the
 * 0x28-byte template data_ov025_020b4178 to a local, binds the cell table gOv025UiCmStrCfgTextPath to
 * the list at ctx+4 (Ov025_InitResourceRecord), overrides the template's field18
 * (Ov025_LookupEntry(9)) and field20 (Ov025_GetCtxBlock968c()), and applies it with TileSurface_InitAndUpload4bpp.
 * The one-surface counterpart of Ov008_SetupMenuSurfaces (Ov008_SetupMenuSurfaces). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Style28 {
    u8  pad_0000[0x18];
    int field18;        /* 0x18 */
    u8  pad_001c[4];
    int field20;        /* 0x20 */
    u8  pad_0024[4];
} Style28;

extern Style28 data_ov025_020b4178;
extern int  gOv025UiCmStrCfgTextPath;
extern void *Ov025_GetPageA(void);
extern void Ov025_InitResourceRecord(void *p, void *tbl);
extern int  Ov025_GetCtxBlock968c(void);
extern int  Ov025_LookupEntry(int a);

void Ov025_SetupMenuSurface(void)
{
    Style28 s = data_ov025_020b4178;
    char *ctx = (char *)Ov025_GetPageA();

    Ov025_InitResourceRecord(ctx + 4, &gOv025UiCmStrCfgTextPath);
    s.field20 = Ov025_GetCtxBlock968c();
    s.field18 = Ov025_LookupEntry(9);
    TileSurface_InitAndUpload4bpp(ctx + 0x10, &s);
}
