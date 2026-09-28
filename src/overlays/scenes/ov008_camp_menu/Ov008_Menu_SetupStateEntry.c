/*
 * Ov008_Menu_SetupStateEntry - configure the menu's toolbar/OAM entries on
 * entering a menu state.
 *
 * Fetches the menu context block (Ov008_GetCtxBlock954c) and queries a small
 * status record via Ov008_GetPoint1C; if its gate halfword is non-zero the
 * state is not ready and it bails. Otherwise it applies control value 1, then
 * on the OAM cell table (Ov008_GetCtxBlock4a80) it hides entries 0x29 and 0x51,
 * fires the object's inner vtable slot 4 and enqueues its gfx command
 * (both on ctx+0x64), shows entry 0x80 and the optional slot at ctx+0x54,
 * releases and re-shows entry 5, and records the new state at ctx+0x14.
 *
 * NB: Obj_InvokeInnerVtable4/EnqueueObjGfxCommand are invoked with only r0 set (ctx+0x64);
 * Ghidra's extraout_r1/param_4 args at that call are decompiler artifacts.
 */

extern int Ov008_GetCtxBlock954c(void);
extern void Ov008_GetPoint1C(int block, void *out);
extern void Ov008_ApplyControlValue(int value);
extern int Ov008_GetCtxBlock4a80(void);
extern int Ov008_FindEntryById(int table, int id);
extern void Ov008_SetEntrySlotsVisible(int table, int entry, int visible);
extern void Obj_InvokeInnerVtable4(int obj);
extern void EnqueueObjGfxCommand(int obj);
extern void Ov008_ReleaseTwoSlotsEx(int table, int entry, int a);

void Ov008_Menu_SetupStateEntry(int param_1, int param_2, int param_3, int param_4)
{
    int blk, tbl, entry;
    unsigned short st[3];

    blk = Ov008_GetCtxBlock954c();
    Ov008_GetPoint1C(blk, st);
    if (st[2] != 0) return;
    Ov008_ApplyControlValue(1);
    tbl = Ov008_GetCtxBlock4a80();
    entry = Ov008_FindEntryById(tbl, 0x29);
    Ov008_SetEntrySlotsVisible(tbl, entry, 0);
    entry = Ov008_FindEntryById(tbl, 0x51);
    Ov008_SetEntrySlotsVisible(tbl, entry, 0);
    Obj_InvokeInnerVtable4(param_1 + 0x64);
    EnqueueObjGfxCommand(param_1 + 0x64);
    entry = Ov008_FindEntryById(tbl, 0x80);
    Ov008_SetEntrySlotsVisible(tbl, entry, 1);
    if (*(int *)(param_1 + 0x54) != 0) {
        Ov008_SetEntrySlotsVisible(tbl, *(int *)(param_1 + 0x54), 1);
    }
    entry = Ov008_FindEntryById(tbl, 5);
    Ov008_ReleaseTwoSlotsEx(tbl, entry, 0);
    entry = Ov008_FindEntryById(tbl, 5);
    Ov008_SetEntrySlotsVisible(tbl, entry, 1);
    *(int *)(param_1 + 0x14) = 0;
}
