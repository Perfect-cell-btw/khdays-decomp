/* Ov008_RegisterSlotCells -- Ov008_RegisterSlotCells (156 B, 8 relocs).
 * Rebuilds the cell list for the current slot page. Looks up the slot table for the page
 * (Ov008_GetPageTableEntry keyed by state->pageId), then for every slot except the currently
 * selected one (state->selected) it registers the slot's inactive-tag cell (table->arrB[i],
 * the byte at +0xd+i) via Ov008_FindEntryByTag + Ov008_TagTracker_InvokeCallback. Finally it emits the
 * table's group tag (Ov008_RetargetCellByTag(table->id, 0, 0)) and registers the selected slot's
 * active-tag cell (table->arrA[state->selected], the byte at +8). state->selected and
 * table->count are re-read on each iteration. */
#include "nitro/types.h"

typedef struct Ov008SlotState {
    s16 selected;       /* 0x0, signed */
    u16 pageId;         /* 0x2 */
} Ov008SlotState;

typedef struct Ov008SlotTable {
    u16 id;             /* 0x0 */
    u8  count;          /* 0x2 */
    u8  pad_0003[5];
    u8  arrA[5];        /* 0x8, active-tag bytes indexed by state->selected */
    u8  arrB[1];        /* 0xd, inactive-tag bytes indexed by the loop index */
} Ov008SlotTable;

extern Ov008SlotState *Ov008_GetMenuContext(void);
extern void *Ov008_GetCtxBlock9500(void);
extern Ov008SlotTable *Ov008_GetPageTableEntry(u16 pageId);
extern void *Ov008_FindEntryByTag(void *ctx, int tag);
extern void  Ov008_TagTracker_InvokeCallback(void *ctx, void *cell);
extern void  Ov008_RetargetCellByTag(u16 tag, int x, int y);

void Ov008_RegisterSlotCells(void)
{
    Ov008SlotState *state = Ov008_GetMenuContext();
    void *ctx = Ov008_GetCtxBlock9500();
    Ov008SlotTable *table = Ov008_GetPageTableEntry(state->pageId);
    int i;

    for (i = 0; i < table->count; i++) {
        if (state->selected != i) {
            Ov008_TagTracker_InvokeCallback(ctx, Ov008_FindEntryByTag(ctx, table->arrB[i]));
        }
    }
    Ov008_RetargetCellByTag(table->id, 0, 0);
    Ov008_TagTracker_InvokeCallback(ctx, Ov008_FindEntryByTag(ctx, table->arrA[state->selected]));
}
