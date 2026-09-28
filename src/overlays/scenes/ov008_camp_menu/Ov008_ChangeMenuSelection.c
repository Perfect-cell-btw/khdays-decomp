/* Ov008_ChangeMenuSelection -- Ov008_ChangeMenuSelection (160 B, 9 relocs).
 * Moves the menu selection to newSel with a fade transition. No-op if already selected
 * (p->sel == newSel). Kicks a fade on the sub-animation at p+0x1c (Tween_Configure target
 * p->field38 << 12, offset newSel ? 0xc0000 : 0, duration param3; then Tween_Start starts it),
 * bumps a global (Ov008_SetCtxField962c(1)), records the new selection (p->sel = newSel), refreshes
 * dependent state (Ov008_DrawStatusPanelLabels), and disables the confirm/back buttons (ids 0x47, 0x48).
 * The offset ternary is written `newSel == 0 ? 0 : 0xc0000` so mwcc emits moveq(#0) before
 * movne(#0xc0000) as the ROM does (the != form flips the two conditional movs). */
#include "nitro/types.h"

typedef struct Ov008SelState {
    u8  pad_0000[0x1c];
    u8  fade[0x38 - 0x1c];   /* 0x1c: fade/animation sub-object */
    int field38;             /* 0x38 */
    u8  pad_003c[0x44 - 0x3c];
    int sel;                 /* 0x44 */
} Ov008SelState;

extern void *Ov008_GetCtxBlock4a80(void);
extern void  Tween_Configure(void *fade, int mode, int target, int a, int dur);
extern void  Tween_Start(void *fade);
extern void  Ov008_SetCtxField962c(int value);
extern void  Ov008_DrawStatusPanelLabels(Ov008SelState *p);
extern void *Ov008_FindEntryById(void *ctx, int id);
extern void  Ov008_SetEntrySlotsVisible(void *ctx, void *widget, int flag);

void Ov008_ChangeMenuSelection(Ov008SelState *p, int newSel, int param3)
{
    void *ctx = Ov008_GetCtxBlock4a80();

    if (p->sel == newSel) {
        return;
    }
    Tween_Configure(&p->fade, 2, p->field38 << 12, newSel == 0 ? 0 : 0xc0000, param3);
    Tween_Start(&p->fade);
    Ov008_SetCtxField962c(1);
    p->sel = newSel;
    Ov008_DrawStatusPanelLabels(p);
    Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 0x47), 0);
    Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 0x48), 0);
}
