/*
 * Ov008_Menu_RefreshSlotPanel - per-frame refresh of the 4 party/panel slots and
 * the selection/session state, one of the two setup steps run when the menu ticks.
 *
 * Builds the "active slots" mask (enabled & not-disabled, 4 bits), reconciles the
 * shared-context status halfword (+0x5c6) with the current mode/selection, and then
 * shows or hides the three UI entries per slot (ids slot+0x6f / +0x79 / +0x83):
 *   - Mode active (Ov008_IsSessionReady): while game flag 0x200c is set, clears bit 2
 *     of each cursor record's byte[2] for slots 1..3.
 *   - Mode inactive: mirrors Ov008_IsBusy into +0x5c6 bit 2, and while flag
 *     0x200c is set plays the confirm/deny sound, latches +0x5c6 bit 8, dispatches
 *     handler 0x200c, refreshes button 5 and primes sub-scene 0 when the cursor
 *     record's byte[3] == 8.
 *   - When not busy (Ov008_Link_IsLocal) and +0x5c6 bit 4 is clear, a session-state
 *     change (mask != prev, or session inactive/other) primes sub-scene 0, dispatches
 *     handlers 0x200c and 0x200a, and latches +0x5c6 bits 8 and 4.
 * For each visible slot it re-shows and re-acquires the three entries and stamps the
 * icon rows from the slot's page (Ov008_MapPageToIconRow) and its record byte[3]
 * (Ov008_PageToIconRow = Ov008_PageToIconRow); invisible slots are hidden.
 *
 * Codegen notes (this is a 1256-byte, all-callee-saved dispatcher):
 *  - +0x5c6 bit reads/writes are 16-bit bitfields (Flags); the per-record byte[2]
 *    bit-2 tests are byte bitfields (BFlags ->c2 == 1); byte[3] loads are unsigned.
 *  - The Session-state booleans are PREDICATED (`if (cond) x = 1;` statements), not
 *    `||` chains, matching the ROM's moveq/movne stream.
 *  - The slot loop tests `(mask & bit) != 0` with the VISIBLE branch as fall-through
 *    (so mwcc caches &stk in fp for the whole loop, not the constant 0).
 *  - `mask` is computed in two steps (load into mask, then AND) so it colours into
 *    the high callee-saved register the ROM uses; and in the slot loop `bVar2` is
 *    declared before `page` so the two byte loads colour r7/r8 as the ROM does.
 */

#include "game/engine.h"

typedef struct {
    unsigned short b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1,
                   b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, b15:1;
} Flags;
typedef struct { unsigned char c0:1, c1:1, c2:1, c3:1, c4:1, c5:1, c6:1, c7:1; } BFlags;

extern int Ov008_GetContext(void);
extern unsigned int Ov008_GetSlotPresenceMask(void);
extern unsigned int Ov008_BuildSlotMatchMask(int a);
extern unsigned int Ov008_GetCachedPlayerMask(void);
extern int Ov008_IsSessionReady(void);
extern int Ov008_GetPlayerRecord(int slot);
extern int Ov008_IsBusy(void);
extern int Ov008_GetSharedRecord(void);
extern void Ov008_UpdateMenuButton5(int a);
extern void Ov008_SetActivePage(int a);
extern void Ov008_PrimeSubSceneFromCursor(int a);
extern int Ov008_Link_IsLocal(void);
extern void Ov008_SetBusyFlag(int a);
extern void Ov008_GetMissionRowInfo(int idx, void *out);
extern int Ov008_IsMenuPageUnlocked(int a);
extern int Ov008_FindEntryById(int ctx, int id);
extern void Ov008_SetEntrySlotsVisible(int ctx, int entry, int visible);
extern void Ov008_ReleaseTwoSlots(int ctx, int entry);
extern void Ov008_ReleaseTwoSlotsEx(int ctx, int entry, int value);
extern unsigned int Ov008_MapPageToIconRow(int a);
extern unsigned int Ov008_PageToIconRow(int a);
extern int data_ov008_02090f1c;

void Ov008_Menu_RefreshSlotPanel(void)
{
    int ctx;
    unsigned int uVar7;
    unsigned int uVar8;
    unsigned int mask;
    int cur;
    int bVar3;
    int i;
    int entry;
    unsigned int stk[2];

    ctx = Ov008_GetContext();
    uVar7 = Ov008_GetSlotPresenceMask();
    uVar8 = Ov008_BuildSlotMatchMask(7);
    mask = Ov008_GetCachedPlayerMask();
    mask = (unsigned short)(~uVar8 & mask);

    if (Ov008_IsSessionReady() != 0) {
        if (GameState_IsFlagSet(0x200c) != 0) {
            i = 1;
            do {
                cur = Ov008_GetPlayerRecord(i);
                i = i + 1;
                if (cur != 0) *(unsigned char *)(cur + 2) &= ~4;
            } while (i < 4);
        }
    } else {
        int bit2 = ((Flags *)(data_ov008_02090f1c + 0x5c6))->b2;
        int uVar12 = Ov008_IsBusy();
        if (uVar12 != 0 && bit2 == 0) {
            ((Flags *)(data_ov008_02090f1c + 0x5c6))->b2 = uVar12;
        } else if (uVar12 == 0 && bit2 != 0) {
            ((Flags *)(data_ov008_02090f1c + 0x5c6))->b2 = uVar12;
        }
        if (GameState_IsFlagSet(0x200c) != 0) {
            int pi = Session_GetLocalPlayerIndex();
            int p1 = Ov008_GetSharedRecord();
            int p2 = Ov008_GetPlayerRecord(pi);
            bVar3 = 0;
            if (((BFlags *)(p1 + 2))->c2 == 1 && ((BFlags *)(p2 + 2))->c2 == 1) {
                PlaySound(0, 3);
                bVar3 = 1;
            } else if (*(unsigned char *)(p1 + 3) != 8 && *(unsigned char *)(p2 + 3) != 8) {
                PlaySound(0, 3);
                bVar3 = 1;
            }
            if (uVar12 == 0 && bit2 != 0) bVar3 = 1;
            if (bVar3) {
                *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x100;
                GameState_ClearFlag(0x200c);
                Ov008_UpdateMenuButton5(1);
                Ov008_SetActivePage(1);
                if (*(unsigned char *)(p1 + 3) == 8) {
                    *(unsigned char *)(p1 + 2) &= ~4;
                    Ov008_PrimeSubSceneFromCursor(0);
                }
            }
        }
    }

    if (Ov008_Link_IsLocal() == 0 && ((Flags *)(data_ov008_02090f1c + 0x5c6))->b4 == 0) {
        int bVar13;
        int keep;
        bVar13 = 0;
        keep = 0;
        if (!Session_Exists()) bVar13 = 1;
        if (mask != uVar7) bVar13 = 1;
        if (Session_Exists()) {
            if (!Session_IsActive()) bVar13 = 1;
            if (Session_IsSceneInterruptible() != 0) { bVar13 = 1; keep = bVar13; }
        }
        if (bVar13) {
            if (GameState_IsFlagSet(0x200c) != 0) {
                Ov008_PrimeSubSceneFromCursor(0);
            }
            GameState_ClearFlag(0x200c);
            GameState_ClearFlag(0x200a);
            Ov008_SetBusyFlag(0);
            Ov008_UpdateMenuButton5(1);
            Ov008_SetActivePage(1);
            if (Ov008_IsSessionReady() != 0) {
                *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x100;
                *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x10;
            } else {
                if (keep) mask = 0;
                *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x100;
                *(unsigned short *)(data_ov008_02090f1c + 0x5c6) |= 0x10;
            }
        }
    }

    i = 0;
    do {
        if ((mask & (1 << i)) != 0) {
            cur = Ov008_GetPlayerRecord(i);
            Ov008_GetMissionRowInfo(i, stk);
            if (cur != 0) {
                int bVar2;
                int page = ((unsigned char *)stk)[5];
                bVar2 = *(unsigned char *)(cur + 3);
                if (Ov008_IsMenuPageUnlocked(page) == 0) page = 0x14;
                if (bVar2 < 0) bVar2 = 0;
                entry = Ov008_FindEntryById(ctx, i + 0x6f);
                Ov008_SetEntrySlotsVisible(ctx, entry, 1);
                entry = Ov008_FindEntryById(ctx, i + 0x79);
                Ov008_SetEntrySlotsVisible(ctx, entry, 1);
                entry = Ov008_FindEntryById(ctx, i + 0x83);
                Ov008_SetEntrySlotsVisible(ctx, entry, 1);
                entry = Ov008_FindEntryById(ctx, i + 0x6f);
                Ov008_ReleaseTwoSlots(ctx, entry);
                entry = Ov008_FindEntryById(ctx, i + 0x79);
                Ov008_ReleaseTwoSlots(ctx, entry);
                entry = Ov008_FindEntryById(ctx, i + 0x83);
                Ov008_ReleaseTwoSlots(ctx, entry);
                entry = Ov008_FindEntryById(ctx, i + 0x6f);
                Ov008_ReleaseTwoSlotsEx(ctx, entry, Ov008_MapPageToIconRow(page) & 0xffff);
                entry = Ov008_FindEntryById(ctx, i + 0x83);
                Ov008_ReleaseTwoSlotsEx(ctx, entry, Ov008_PageToIconRow(bVar2) & 0xffff);
            }
        } else {
            entry = Ov008_FindEntryById(ctx, i + 0x6f);
            Ov008_SetEntrySlotsVisible(ctx, entry, 0);
            entry = Ov008_FindEntryById(ctx, i + 0x79);
            Ov008_SetEntrySlotsVisible(ctx, entry, 0);
            entry = Ov008_FindEntryById(ctx, i + 0x83);
            Ov008_SetEntrySlotsVisible(ctx, entry, 0);
        }
        i = i + 1;
    } while (i < 4);
}
