/* Ov025_UpdateMenuButton5 -- Ov008_UpdateMenuButton5 (116 B, 7 relocs).
 * Updates menu button id 5's enabled state when a tracked value changes. Bails unless the global
 * gate data_ov025_020b575c is set and the new value differs from the cached one
 * (ctx1->fieldC) -- a short-circuit `||` guard. Caches the new value (ctx1->fieldC = param_1),
 * gets the widget context (02050c64), looks up widget id 5, then: if param_1 != 0 it primes the
 * widget (Ov025_ReleaseTwoSlotsEx_2(ctx, widget, 0)) and enables it (Ov025_SetEntrySlotsVisible(ctx, widget,
 * 1)); otherwise it just disables it (Ov025_SetEntrySlotsVisible(ctx, widget, 0)). */
#include "nitro/types.h"

typedef struct Ov008Ctx1 { u8 pad_0000[0xc]; int fieldC; } Ov008Ctx1;

extern Ov008Ctx1 *Ov025_GetPageB(void);
extern int   data_ov025_020b575c;
extern void *Ov025_GetBlock4a80(void);
extern void *Ov025_FindEntryById(void *ctx, int id);
extern void  Ov025_ReleaseTwoSlotsEx_2(void *ctx, void *widget, int value);
extern void  Ov025_SetEntrySlotsVisible(void *ctx, void *widget, int flag);

void Ov025_UpdateMenuButton5(int param_1)
{
    Ov008Ctx1 *ctx1 = Ov025_GetPageB();
    void *ctx2;
    void *widget;

    if (data_ov025_020b575c == 0 || ctx1->fieldC == param_1) {
        return;
    }
    ctx1->fieldC = param_1;
    ctx2 = Ov025_GetBlock4a80();
    widget = Ov025_FindEntryById(ctx2, 5);
    if (param_1 != 0) {
        Ov025_ReleaseTwoSlotsEx_2(ctx2, widget, 0);
        Ov025_SetEntrySlotsVisible(ctx2, widget, 1);
    } else {
        Ov025_SetEntrySlotsVisible(ctx2, widget, 0);
    }
}
