/* Ov008_SetupMenuDisplay_2 -- Ov008_SetupMenuDisplay (212 B, 12 relocs).
 * One-shot display setup for a menu screen. Builds the two SRT/display objects embedded in the
 * scene struct (Draw_ScaledValue on p+0x124 with params 4,0xe and on p+0x250 with 0xf,0xf), advances
 * the first (EnqueueObjGfxCommand) and binds the second to p->field2e0 (TileSurface_SetCurrentItem), enables the 0x5c
 * cell (Ov008_ResolveEntryAndConfigure) and re-links it (Ov008_SwapParamOverrides / Ov008_SetTag3RowPos on the
 * widget from Ov008_FindEntryById), then registers the screen via Ov008_RepaintTextRow with the
 * count from Ov008_GetVarRecordByIndex(p+0x28c, 8). Takes 5 args (arg5 on the stack). */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008Setup {
    u8  pad_0000[0x124];
    u8  field124[0x250 - 0x124];   /* 0x124: SRT/display object A */
    u8  field250[0x28c - 0x250];   /* 0x250: SRT/display object B */
    u8  field28c[0x2e0 - 0x28c];   /* 0x28c */
    int field2e0;                  /* 0x2e0 */
} Ov008Setup;

extern void  Ov008_DrawMenuEntry(Ov008Setup *p, int a, int b);
extern void  EnqueueObjGfxCommand(void *base);
extern void  TileSurface_SetCurrentItem(void *base, int target, int update);
extern void  Ov008_ResolveEntryAndConfigure(void *ctx, int id, int flag);
extern void *Ov008_FindEntryById(void *ctx, int id);
extern void  Ov008_SwapParamOverrides(void *ctx, void *widget);
extern void  Ov008_SetTag3RowPos(void *widget);
extern int   Ov008_GetVarRecordByIndex(void *base, int n);
extern void  Ov008_RepaintTextRow(Ov008Setup *p, int a, int b, int c);

void Ov008_SetupMenuDisplay_2(Ov008Setup *p, void *arg2, int arg3, int arg4, int arg5)
{
    Draw_ScaledValue(&p->field124, arg3, 4, 0xe, 0);
    Ov008_DrawMenuEntry(p, arg4, arg5 + 1);
    EnqueueObjGfxCommand(&p->field124);
    Draw_ScaledValue(&p->field250, arg3, 0xf, 0xf, 0);
    TileSurface_SetCurrentItem(&p->field250, p->field2e0, 1);
    Ov008_ResolveEntryAndConfigure(arg2, 0x5c, 1);
    Ov008_SwapParamOverrides(arg2, Ov008_FindEntryById(arg2, 0x5c));
    Ov008_SetTag3RowPos(Ov008_FindEntryById(arg2, 0x5c));
    Ov008_RepaintTextRow(p, 0, Ov008_GetVarRecordByIndex(&p->field28c, 8), 0xf3);
}
