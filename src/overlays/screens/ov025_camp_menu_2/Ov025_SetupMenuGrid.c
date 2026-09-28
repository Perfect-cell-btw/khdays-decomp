/* Ov025_SetupMenuGrid -- Ov008_SetupMenuGrid (244 B, 10 relocs).
 * Display setup for a grid-style menu screen (variant of Ov008_SetupMenuDisplay_2). Builds the first
 * SRT/display object at p+0x124 (Draw_ScaledValue params 4,0xe), draws the entry via
 * Ov025_DrawMenuEntry(p, arg4, arg5 + 1), and advances it (EnqueueObjGfxCommand). Then, for the two grid
 * rows i = 0,1: builds the display object slot (p+0x160)[i+3] (0x3c stride) with Draw_ScaledValue
 * params (id, 0xf), where id runs 0xd, 0x10, and binds it to the row's target
 * ((E16 *)(p+0x2cc))[i].v via TileSurface_SetCurrentItem. Finally enables cells 0x55 and 0x56
 * (Ov025_ResolveEntryAndConfigure) and re-links widget 0x56 (Ov025_SwapParamOverrides / Ov025_ConfigureSlotWithHeight on
 * the widget from Ov025_FindEntryById). arg2 is the widget context; takes 5 args (arg5 on the
 * stack). Row target reads use a 16-byte struct subscript so mwcc recomputes p + i*0x10 each
 * iteration (index addressing) instead of adding an induction variable. */
typedef unsigned char u8;

typedef struct DisplayObj {
    u8  b[0x3c];
} DisplayObj;

typedef struct E16 {
    int v;
    u8  pad[12];
} E16;

typedef struct Ov008Setup {
    u8  pad_0000[0x124];
    u8  field124[0x250 - 0x124];   /* 0x124: SRT/display object A */
} Ov008Setup;

extern void  Draw_ScaledValue(void *base, int a, int b, int c, int d);
extern void  Ov025_DrawMenuEntry(Ov008Setup *p, int a, int b);
extern void  EnqueueObjGfxCommand(void *base);
extern void  TileSurface_SetCurrentItem(void *base, int target, int update);
extern void  Ov025_ResolveEntryAndConfigure(void *ctx, int id, int flag);
extern void *Ov025_FindEntryById(void *ctx, int id);
extern void  Ov025_SwapParamOverrides(void *ctx, void *widget);
extern void  Ov025_ConfigureSlotWithHeight(void *widget);

void Ov025_SetupMenuGrid(Ov008Setup *p, void *arg2, int arg3, int arg4, int arg5)
{
    int i;
    int id;

    Draw_ScaledValue(&p->field124, arg3, 4, 0xe, 0);
    Ov025_DrawMenuEntry(p, arg4, arg5 + 1);
    EnqueueObjGfxCommand(&p->field124);
    i = 0;
    id = 0xd;
    for (; i < 2; i++) {
        DisplayObj *slot = (DisplayObj *)((char *)p + 0x160) + (i + 3);
        Draw_ScaledValue(slot, arg3, id, 0xf, 0);
        TileSurface_SetCurrentItem(slot, ((E16 *)((char *)p + 0x2cc))[i].v, 1);
        id += 3;
    }
    for (i = 0x55; i <= 0x56; i++) {
        Ov025_ResolveEntryAndConfigure(arg2, i, 1);
    }
    Ov025_SwapParamOverrides(arg2, Ov025_FindEntryById(arg2, 0x56));
    Ov025_ConfigureSlotWithHeight(Ov025_FindEntryById(arg2, 0x56));
}
