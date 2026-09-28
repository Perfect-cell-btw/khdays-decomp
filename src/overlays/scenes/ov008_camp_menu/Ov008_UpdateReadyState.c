/* Ov008_UpdateReadyState -- Ov008_UpdateReadyState (212 B, 11 relocs).
 * Enables the confirm widgets once the screen is "ready". Bails unless flag bit 2 of p->flags380
 * is set and both sentinel counters p->field384 and p->field388 have reached 0x7fffffff. Then it
 * clears p->field4, pulses Ov008_SetCtxField95fc(1) and Ov008_SetCtxField9628(0), and enables widget
 * id 3 (Ov008_SetEntrySlotsVisible on the widget from Ov008_FindEntryById). Finally, when p->field10 == 2
 * it re-enables widget 3 and re-links widget 0x51 (only if p->field8 == 1); otherwise it just
 * re-enables widget 3. */

#include "nitro/types.h"

typedef struct Ov008EndState {
    u8  pad_0000[4];
    int field4;          /* 0x4 */
    int field8;          /* 0x8 */
    u8  pad_000c[0x10 - 0xc];
    int field10;         /* 0x10 */
    u8  pad_0014[0x380 - 0x14];
    struct { unsigned b0:1; unsigned b1:1; unsigned b2:1; unsigned rest:29; } flags380; /* 0x380 */
    int field384;        /* 0x384 */
    int field388;        /* 0x388 */
} Ov008EndState;

extern void *Ov008_GetContext(void);
extern void  Ov008_SetCtxField95fc(int a);
extern void  Ov008_SetCtxField9628(int value);
extern void *Ov008_FindEntryById(void *ctx, int id);
extern void  Ov008_SetEntrySlotsVisible(void *ctx, void *widget, int flag);
extern void  Ov008_SetTag3RowPos(void *widget);

void Ov008_UpdateReadyState(Ov008EndState *p)
{
    void *ctx = Ov008_GetContext();
    if (p->flags380.b2 == 0) {
        return;
    }
    if (p->field384 != 0x7fffffff || p->field388 != 0x7fffffff) {
        return;
    }
    p->field4 = 0;
    Ov008_SetCtxField95fc(1);
    Ov008_SetCtxField9628(0);
    Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 3), 1);
    if (p->field10 == 2) {
        if (p->field8 != 1) {
            return;
        }
        Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 3), 1);
        Ov008_SetTag3RowPos(Ov008_FindEntryById(ctx, 0x51));
    } else {
        Ov008_SetEntrySlotsVisible(ctx, Ov008_FindEntryById(ctx, 3), 1);
    }
}
