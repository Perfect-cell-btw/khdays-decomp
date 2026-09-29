/*
 * Ov008_Menu_RefreshSubitemGrid - per-frame refresh of the menu's sub-item
 * availability grid (the second of the two setup steps run on menu tick).
 *
 * Copies the 7-entry sub-item id table from data_ov008_0208e958 into a stack
 * buffer, records the current mode/flag state into the shared-context status
 * halfword (+0x5c6 bits 0/1/3), and toggles the two action entries: 0x94 (shown
 * only when an action is available - gated on the cursor record byte[3], the input
 * branch Ov008_IsSessionReady ? Ov008_AreSelectedMenuSlotsReady : Ov008_IsBusy, and the
 * busy gates +0x5c6 bit5 / Ov008_PageB_GetBusy / Ov008_PageB_HasPending) and 0x93.
 * If the state changed (or +0x5c6 bit 8 is still set), it rebuilds the 7 sub-item
 * enable flags from game progression - all-on when flag 0x200c is set; otherwise
 * from the day counter (GameState_GetField(0,9)) and per-item flags - stamps a
 * callback (Ov008_HandleMenuEntrySelection) at ctx+0x4a50, pushes each flag to entries
 * 0x65..0x6b (Ov008_PushSubitemSet), and repositions the selector at the chosen
 * sub-item.
 *
 * Codegen notes:
 *  - `unsigned int flags[7] = {0};` (array initialiser) is what makes mwcc zero the
 *    stack flags with a HELD base pointer (add rX,sp,#0x1c; str) matching the ROM;
 *    zeroing them with 7 explicit `flags[i] = 0;` assignments instead uses direct
 *    [sp,#N] offsets and drops the base-pointer instruction (one byte short).
 *  - +0x5c6 accesses are 16-bit bitfields; ctx+0x5c8 uses array indexing
 *    (((unsigned int *)ctx)[0x172]) so mwcc emits the ldr/str offset, not an add.
 *  - The bVar4 input branch is `ed3c != 0 ? 570c0 : ebf0` (ROM beq to the ebf0 arm)
 *    and the entry-0x93 visibility normalises `ebf0() != 0` into bVar4 before the
 *    FindEntryById, matching the ROM's early movne/moveq.
 *  - Ov008_Menu_PositionSelector (the selector) is called K&R-style so the tail can pass 2
 *    args sharing uVar13; Ov008_StoreWordAt0x4a50 takes (ctx, callback-pointer).
 */

#include "game/engine.h"

typedef struct {
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1,
                   b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1;
} Flags;
typedef struct { unsigned int w[7]; } W7;

extern int Ov008_IsSessionReady(void);
extern int Ov008_GetPlayerRecord(int slot);
extern int Ov008_IsBusy(void);
extern int Ov008_AreSelectedMenuSlotsReady(void);
extern int Ov008_PageB_GetBusy(void);
extern int Ov008_PageB_HasPending(void);
extern int Ov008_GetContext(void);
extern int Ov008_FindEntryById(int ui, int id);
extern int Ov008_GetField84Bit1(int ui, int entry);
extern void Ov008_SetEntrySlotsVisible(int ui, int entry, int visible);
extern void Ov008_ReleaseTwoSlots_2(int ui, int entry);
extern void Ov008_StoreWordAt0x4a50(int ui, int val);
extern int Ov008_IsMode4(void);
extern int Ov008_GetWordAt0x4a70(int ui);
extern void Ov008_SwapParamOverrides(int ui, int entry);
extern void Ov008_PushSubitemSet(int ui, int entry, int val);
extern void Ov008_Menu_PositionSelector();
extern void Ov008_DrawMenuValue(int ctx);
extern int Ov008_GetSlideTableValue(int a);
extern void Ov008_HandleMenuEntrySelection(void);
extern int data_ov008_0208e958;
extern int data_ov008_02090f1c;

void Ov008_Menu_RefreshSubitemGrid(void)
{
    unsigned int flags[7] = {0};
    unsigned int values[7];
    int ctxp;
    int ui;
    unsigned short sVar1;
    unsigned short sVar2;
    int bVar4;
    int e;
    unsigned int uVar13;
    int i;

    *(W7 *)values = *(W7 *)&data_ov008_0208e958;
    ctxp = data_ov008_02090f1c;
    if (ctxp == 0) return;

    sVar1 = *(unsigned short *)(ctxp + 0x5c6);
    ((Flags *)(data_ov008_02090f1c + 0x5c6))->b0 = Ov008_IsSessionReady();
    ((Flags *)(data_ov008_02090f1c + 0x5c6))->b1 = GameState_IsFlagSet(0x200b);
    ((Flags *)(data_ov008_02090f1c + 0x5c6))->b3 = GameState_IsFlagSet(0x200c);
    sVar2 = *(unsigned short *)(data_ov008_02090f1c + 0x5c6);

    ui = Ov008_GetContext();
    e = Ov008_GetPlayerRecord(Session_GetLocalPlayerIndex());
    bVar4 = 0;
    if (*(unsigned char *)(e + 3) != 8) {
        if (Ov008_IsSessionReady() != 0) bVar4 = Ov008_AreSelectedMenuSlotsReady();
        else bVar4 = Ov008_IsBusy();
    }
    if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b5) bVar4 = 0;
    if (Ov008_PageB_GetBusy() != 0) bVar4 = 0;
    if (Ov008_PageB_HasPending()) bVar4 = 0;
    if (bVar4 != 0) {
        e = Ov008_FindEntryById(ui, 0x94);
        if (Ov008_GetField84Bit1(ui, e) == 0) {
            e = Ov008_FindEntryById(ui, 0x94);
            Ov008_SetEntrySlotsVisible(ui, e, 1);
            e = Ov008_FindEntryById(ui, 0x94);
            Ov008_ReleaseTwoSlots_2(ui, e);
        }
    } else {
        e = Ov008_FindEntryById(ui, 0x94);
        if (Ov008_GetField84Bit1(ui, e) != 0) {
            e = Ov008_FindEntryById(ui, 0x94);
            Ov008_SetEntrySlotsVisible(ui, e, 0);
        }
    }
    bVar4 = Ov008_IsBusy() != 0;
    e = Ov008_FindEntryById(ui, 0x93);
    Ov008_SetEntrySlotsVisible(ui, e, bVar4);

    if (sVar1 == sVar2 && ((Flags *)(data_ov008_02090f1c + 0x5c6))->b8 == 0) return;
    *(unsigned short *)(data_ov008_02090f1c + 0x5c6) &= ~0x100;

    if (GameState_IsFlagSet(0x200c) != 0) {
        Ov008_StoreWordAt0x4a50(ui, 0);
        i = 0;
        do { flags[i] = 1; i = i + 1; } while (i < 7);
    } else {
        if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b5) {
            Ov008_StoreWordAt0x4a50(ui, (int)Ov008_HandleMenuEntrySelection);
            i = 0;
            do { flags[i] = 1; i = i + 1; } while (i < 7);
        } else {
            Ov008_StoreWordAt0x4a50(ui, (int)Ov008_HandleMenuEntrySelection);
            i = 0;
            do { flags[i] = 0; i = i + 1; } while (i < 7);
            if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b4) {
                flags[0] = 1;
                flags[1] = 1;
                flags[2] = 1;
                flags[3] = 1;
                flags[4] = 1;
            } else {
                if (Ov008_IsSessionReady() == 0) flags[0] = 1;
            }
            if (GameState_IsFlagSet(0x200b) != 0) {
                flags[5] = 1;
            } else {
                int day = GameState_GetField(0, 9);
                int base = Ov008_GetSlideTableValue(0xb);
                if (day < 0xb) flags[1] = 1;
                if (day <= 0x1a && GameState_IsFlagSet(base + 0x3c2b) == 0) flags[2] = 1;
            }
        }
    }

    if (Ov008_IsMode4()) return;

    uVar13 = ((unsigned int *)data_ov008_02090f1c)[0x172];
    if (uVar13 != 0xffffffff) {
        ((unsigned int *)data_ov008_02090f1c)[0x172] = 0xffffffff;
    } else {
        e = Ov008_GetWordAt0x4a70(ui);
        uVar13 = 0xffffffff;
        if (e != 0) {
            unsigned int key = *(unsigned int *)(e + 0xc);
            i = 0;
            do {
                if (key == values[i]) {
                    if (flags[i] == 0) uVar13 = values[i];
                    break;
                }
                i = i + 1;
            } while (i < 7);
        }
        if ((int)uVar13 < 0) {
            i = 0;
            do {
                if (flags[i] == 0) { uVar13 = values[i]; break; }
                i = i + 1;
            } while (i < 7);
        }
    }

    if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b5 == 0) {
        e = Ov008_FindEntryById(ui, 9);
        Ov008_SwapParamOverrides(ui, e);
        *(int *)(data_ov008_02090f1c + 0x88) = 9;
    }
    e = Ov008_FindEntryById(ui, 0x65); Ov008_PushSubitemSet(ui, e, flags[0]);
    e = Ov008_FindEntryById(ui, 0x66); Ov008_PushSubitemSet(ui, e, flags[1]);
    e = Ov008_FindEntryById(ui, 0x67); Ov008_PushSubitemSet(ui, e, flags[2]);
    e = Ov008_FindEntryById(ui, 0x68); Ov008_PushSubitemSet(ui, e, flags[3]);
    e = Ov008_FindEntryById(ui, 0x69); Ov008_PushSubitemSet(ui, e, flags[4]);
    e = Ov008_FindEntryById(ui, 0x6a); Ov008_PushSubitemSet(ui, e, flags[5]);
    e = Ov008_FindEntryById(ui, 0x6b); Ov008_PushSubitemSet(ui, e, flags[6]);

    if (((Flags *)(data_ov008_02090f1c + 0x5c6))->b5 == 0) {
        if (uVar13 != 0xffffffff) {
            Ov008_Menu_PositionSelector(1, uVar13);
            Ov008_DrawMenuValue(data_ov008_02090f1c);
        } else {
            Ov008_Menu_PositionSelector(0, uVar13);
            Ov008_DrawMenuValue(data_ov008_02090f1c);
        }
    }
}
