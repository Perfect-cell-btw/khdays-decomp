/* Ov008_TickMenuScrollInput -- Ov008_TickMenuScrollInput (460 B, 26 relocs).
 * Menu list scroll/selection tick. When the input-latch bit 0x400 of data_0204c18c is set it reads
 * the pad (Ov008_ReadInputHeader): the up bit (0x40) scrolls to entry list[sel-1], the down bit
 * (0x80) to list[sel+1], each via Ov008_ScrollMenuMoveTo, playing a click when the scroll actually
 * moved and clearing the ctx+0x10 pending flag. When the latch is clear it settles the selection:
 * commits the pending change (Ov008_ChangeMenuSelection, direction from ctx+0x44) with a confirm sound,
 * hides the up/down arrows (0x29/0x51), swaps entry 5 in, re-runs the layer object, shows entry
 * 0x80 (and the optional ctx+0x54 entry), and clears the busy flag ctx+8. */

#include "nitro/types.h"

extern u16  data_0204c18c;

extern unsigned short  Ov008_ReadInputHeader(void);
extern int  Ov008_ScrollMenuMoveTo(int ctx, int bound, int b, int c);
extern void PlaySound(int a, int b);
extern void Ov008_ApplyControlValue(int a);
extern int  Ov008_GetCtxBlock4a80(void);
extern void Ov008_ChangeMenuSelection(int ctx, int newSel, int param3);
extern int  Ov008_FindEntryById(int root, int id);
extern void Ov008_SetEntrySlotsVisible(int root, int entry, int vis);
extern void Ov008_ReleaseTwoSlotsEx(int root, int entry, int n);
extern void Obj_InvokeInnerVtable4(int surface);
extern void EnqueueObjGfxCommand(int dctx);

void Ov008_TickMenuScrollInput(int param_1)
{
    int block, entry;

    if ((data_0204c18c & 0x400) != 0) {
        if (*(int *)(param_1 + 0x44) == 1)
            return;
        if (Ov008_ReadInputHeader() & 0x40) {
            if (Ov008_ScrollMenuMoveTo(param_1, *(int *)(param_1 + 0x50) - 1, 1, 0) != 0)
                PlaySound(0, 0);
            *(int *)(param_1 + 0x10) = 0;
            return;
        }
        if (Ov008_ReadInputHeader() & 0x80) {
            if (Ov008_ScrollMenuMoveTo(param_1, *(int *)(param_1 + 0x50) + 1, 1, 0) != 0)
                PlaySound(0, 0);
            *(int *)(param_1 + 0x10) = 0;
        }
        return;
    }

    Ov008_ApplyControlValue(1);
    block = Ov008_GetCtxBlock4a80();
    if (*(int *)(param_1 + 0x10) != 0) {
        if (*(int *)(param_1 + 0x44) == 1) {
            Ov008_ChangeMenuSelection(param_1, 0, 100);
            PlaySound(0, 2);
        } else {
            Ov008_ChangeMenuSelection(param_1, 1, 100);
            PlaySound(0, 2);
        }
    }
    entry = Ov008_FindEntryById(block, 0x29);
    Ov008_SetEntrySlotsVisible(block, entry, 0);
    entry = Ov008_FindEntryById(block, 0x51);
    Ov008_SetEntrySlotsVisible(block, entry, 0);
    entry = Ov008_FindEntryById(block, 5);
    Ov008_ReleaseTwoSlotsEx(block, entry, 0);
    entry = Ov008_FindEntryById(block, 5);
    Ov008_SetEntrySlotsVisible(block, entry, 1);
    Obj_InvokeInnerVtable4(param_1 + 0x64);
    EnqueueObjGfxCommand(param_1 + 0x64);
    entry = Ov008_FindEntryById(block, 0x80);
    Ov008_SetEntrySlotsVisible(block, entry, 1);
    if (*(int *)(param_1 + 0x54) != 0)
        Ov008_SetEntrySlotsVisible(block, *(int *)(param_1 + 0x54), 1);
    *(int *)(param_1 + 8) = 0;
}
