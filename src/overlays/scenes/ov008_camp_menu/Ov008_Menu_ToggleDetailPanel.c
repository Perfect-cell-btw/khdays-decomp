/*
 * Ov008_Menu_ToggleDetailPanel - enter (param_1 != 0) or leave (param_1 == 0) the
 * menu's detail panel, reconfiguring which UI entries are visible and moving the
 * selector.
 *
 * Always records the panel state in shared-context +0x5c6 bit 5 and sets entries
 * 7 and 8 visible to match param_1. On enter it fires the tag-2 callback, hides
 * the main-list entries (0x10/0x11/0x12/0xe/0xf), draws the detail label (var
 * record 0x15) into the widget at +0x4c, snaps the selector (entry 0x15) to that
 * entry saving its position at +0x5cc/+0x5d0, and latches +0x5c6 bit 8. On leave
 * it runs the teardown (Ov008_PushCountersToEventFlags), shows the main-list entries again,
 * restores the selector to the saved +0x5cc position, points it at target 0x6b,
 * redraws the menu value, latches bit 8 and records target 0x6b at +0x5c8.
 *
 * Codegen notes:
 *  - The +0x5c6 bit-5 write is a bitfield store (->b5 = param_1); mwcc emits the
 *    lsl16/lsr16/lsl31/bic/orr-lsr26 read-modify-write from that alone.
 *  - Ov008_Menu_PositionSelector is called K&R-style (no prototype) so the enter path can
 *    pass 4 args (the selector's nY/nX ride in r2/r3 as the ROM leaves them) while
 *    the leave path passes 2. Caching the context pointer in `gp` keeps it in one
 *    register across the +0x5cc/+0x5d0 store pair (the ROM reuses the now-dead ctx
 *    register), and the 4-arg call forces nX->r3 / nY->r2 so the field loads stay
 *    two ldr (not a coalesced ldm).
 */

#include "game/engine.h"

typedef struct { int nX; int nY; } UiLayoutPos;
typedef struct {
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1,
                   b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1;
} Flags;

extern int Ov008_GetCtxBlock9500(void);
extern int Ov008_GetContext(void);
extern int Ov008_FindEntryById(int ctx, int id);
extern void Ov008_SetEntrySlotsVisible(int ctx, int entry, int visible);
extern int Ov008_FindEntryByTag(int block, unsigned int tag);
extern void Ov008_TagTracker_InvokeCallback(int owner, int tag);
extern int Ov008_GetVarRecordByIndex(int recs, int index);
extern void EnqueueObjGfxCommand(void *obj);
extern UiLayoutPos *Ov008_GetEntryPos(int ctx, int entry);
extern void Ov008_SetEntryPos(int ctx, int entry, UiLayoutPos *pos);
extern void Ov008_Menu_PositionSelector();
extern void Ov008_PushCountersToEventFlags(void);
extern void Ov008_DrawMenuValue(int ctx);
extern int data_ov008_02090f1c;

void Ov008_Menu_ToggleDetailPanel(int param_1)
{
    int block;
    int ctx;
    int entry;
    int *rec;
    int nX, nY, gp;
    UiLayoutPos *pos;

    block = Ov008_GetCtxBlock9500();
    ctx = Ov008_GetContext();
    ((Flags *)(data_ov008_02090f1c + 0x5c6))->b5 = param_1;
    entry = Ov008_FindEntryById(ctx, 7);
    Ov008_SetEntrySlotsVisible(ctx, entry, param_1);
    entry = Ov008_FindEntryById(ctx, 8);
    Ov008_SetEntrySlotsVisible(ctx, entry, param_1);
    if (param_1 != 0) {
        entry = Ov008_FindEntryByTag(block, 2);
        Ov008_TagTracker_InvokeCallback(block, entry);
        entry = Ov008_FindEntryById(ctx, 0x10); Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        entry = Ov008_FindEntryById(ctx, 0x11); Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        entry = Ov008_FindEntryById(ctx, 0x12); Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        entry = Ov008_FindEntryById(ctx, 0xe); Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        entry = Ov008_FindEntryById(ctx, 0xf); Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        rec = (int *)Ov008_GetVarRecordByIndex(data_ov008_02090f1c + 4, 0x15);
        Obj_InvokeInnerVtable4((void *)(data_ov008_02090f1c + 0x4c));
        Text_DrawWithShadow((void *)(data_ov008_02090f1c + 0x4c), 10, 0, 2, rec, 1);
        EnqueueObjGfxCommand((void *)(data_ov008_02090f1c + 0x4c));
        entry = Ov008_FindEntryById(ctx, 0x15);
        pos = Ov008_GetEntryPos(ctx, entry);
        nX = pos->nX;
        nY = pos->nY;
        gp = data_ov008_02090f1c;
        *(int *)(gp + 0x5cc) = nX;
        *(int *)(gp + 0x5d0) = nY;
        Ov008_Menu_PositionSelector(1, 8, nY, nX);
        *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x100;
        return;
    }
    Ov008_PushCountersToEventFlags();
    entry = Ov008_FindEntryById(ctx, 0x10); Ov008_SetEntrySlotsVisible(ctx, entry, 1);
    entry = Ov008_FindEntryById(ctx, 0x11); Ov008_SetEntrySlotsVisible(ctx, entry, 1);
    entry = Ov008_FindEntryById(ctx, 0x12); Ov008_SetEntrySlotsVisible(ctx, entry, 1);
    entry = Ov008_FindEntryById(ctx, 0xe); Ov008_SetEntrySlotsVisible(ctx, entry, 1);
    entry = Ov008_FindEntryById(ctx, 0xf); Ov008_SetEntrySlotsVisible(ctx, entry, 1);
    entry = Ov008_FindEntryById(ctx, 0x15);
    Ov008_SetEntryPos(ctx, entry, (UiLayoutPos *)(data_ov008_02090f1c + 0x5cc));
    Ov008_Menu_PositionSelector(1, 0x6b);
    Ov008_DrawMenuValue(data_ov008_02090f1c);
    *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x100;
    *(int *)(data_ov008_02090f1c + 0x5c8) = 0x6b;
}
