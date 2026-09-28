/* Ov008_UpdateButton3State -- Ov008_UpdateButton3State (128 B, 6 relocs).
 * Toggles menu widget id 3 in sync with the Ov008_PageB_GetBusy() condition, using
 * state->field48 to remember whether it is currently disabled so the work is done only on the
 * transition. When the condition holds and the button is not already disabled, it disables
 * widget 3 and sets state->field48 = 1; when the condition clears and the button is currently
 * disabled, it re-enables widget 3 and clears state->field48. The widget context comes from
 * Ov008_GetContext; the enable flag is pushed via Ov008_SetEntrySlotsVisible. */

#include "nitro/types.h"

typedef struct Ov008ToggleState {
    u8  pad_0000[0x48];
    int field48;            /* 0x48: 1 while widget 3 is disabled */
} Ov008ToggleState;

extern void *Ov008_GetContext(void);
extern int   Ov008_PageB_GetBusy(void);
extern void *Ov008_FindEntryById(void *ctx, int id);
extern void  Ov008_SetEntrySlotsVisible(void *ctx, void *widget, int flag);

void Ov008_UpdateButton3State(Ov008ToggleState *param_1)
{
    void *ctx = Ov008_GetContext();

    if (Ov008_PageB_GetBusy() != 0) {
        if (param_1->field48 != 0) {
            return;
        }
        Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 3), 0);
        param_1->field48 = 1;
    } else {
        if (param_1->field48 == 0) {
            return;
        }
        Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 3), 1);
        param_1->field48 = 0;
    }
}
