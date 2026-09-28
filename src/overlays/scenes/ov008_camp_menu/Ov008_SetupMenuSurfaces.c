/* Ov008_SetupMenuSurfaces -- Ov008_SetupMenuSurfaces (236 B, 14 relocs).
 * Configures the menu's two render surfaces (arg0+0x10 and arg0+0x4c) from style templates and
 * draws a value onto the second. Copies the two 0x28-byte style templates (data_ov008_0208e974,
 * data_ov008_0208e99c) to locals, overrides each one's field18 (Ov008_ResetEntry(9)) and
 * field20 (Ov008_GetCtxBlock968c()), then applies them with TileSurface_InitAndUpload4bpp. Sets arg0->field74 = 1,
 * ticks Ov008_Menu_UpdateDirectionalPrompt, renders a cell built from Ov008_GetVarRecordByIndex(arg0+4, 9) onto the
 * arg0+0x4c surface (Text_DrawWithShadow(.., 0x56, 0, 2, cell, 0)), flushes both surfaces
 * (EnqueueObjGfxCommand), and releases slot 9 (Ov008_MarkSlotUsed). */
#include "nitro/types.h"

typedef struct Style28 {
    u8  pad_0000[0x18];
    int field18;        /* 0x18 */
    u8  pad_001c[4];
    int field20;        /* 0x20 */
    u8  pad_0024[4];
} Style28;

extern Style28 data_ov008_0208e974;
extern Style28 data_ov008_0208e99c;
extern int  Ov008_GetCtxBlock968c(void);
extern int  Ov008_ResetEntry(int a);
extern void TileSurface_InitAndUpload4bpp(void *dst, Style28 *src);
extern void Ov008_Menu_UpdateDirectionalPrompt(void *p);
extern int  Ov008_GetVarRecordByIndex(void *p, int v);
extern void Text_DrawWithShadow(void *surface, int a, int b, int c, int d, int e);
extern void EnqueueObjGfxCommand(void *surface);
extern void Ov008_MarkSlotUsed(int a);

void Ov008_SetupMenuSurfaces(void *arg0)
{
    char *p = (char *)arg0;
    Style28 s1 = data_ov008_0208e974;
    Style28 s2 = data_ov008_0208e99c;

    s1.field20 = Ov008_GetCtxBlock968c();
    s1.field18 = Ov008_ResetEntry(9);
    s2.field20 = Ov008_GetCtxBlock968c();
    s2.field18 = Ov008_ResetEntry(9);
    TileSurface_InitAndUpload4bpp(p + 0x10, &s1);
    TileSurface_InitAndUpload4bpp(p + 0x4c, &s2);
    *(int *)(p + 0x74) = 1;
    Ov008_Menu_UpdateDirectionalPrompt(arg0);
    Text_DrawWithShadow(p + 0x4c, 0x56, 0, 2, Ov008_GetVarRecordByIndex(p + 4, 9), 0);
    EnqueueObjGfxCommand(p + 0x4c);
    EnqueueObjGfxCommand(p + 0x10);
    Ov008_MarkSlotUsed(9);
}
